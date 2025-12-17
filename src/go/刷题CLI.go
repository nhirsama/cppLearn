package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"math/rand"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strconv"
	"strings"
	"time"
)

// --- 常量配置 ---
const (
	DataDir     = "data"
	StatsFile   = "stats.json"
	ConfigFile  = "config.json"
	DefaultFile = "questions.txt"
)

// --- 数据结构 ---

type Option struct {
	Label string
	Text  string
	IsKey bool
}

type Question struct {
	OriginalIndex string
	Content       string // 用作唯一标识 (Key)
	Options       []Option
	// 运行时临时字段
	TempWeight float64
}

// 统计信息
type QuestionStat struct {
	ShownCount   int `json:"shown"`
	CorrectCount int `json:"correct"`
}

type AppConfig struct {
	LastFilename string `json:"last_filename"`
}

// --- 颜色工具 ---
const (
	ColorReset  = "\033[0m"
	ColorRed    = "\033[31m"
	ColorGreen  = "\033[32m"
	ColorYellow = "\033[33m"
	ColorBlue   = "\033[34m"
	ColorCyan   = "\033[36m"
	ColorBold   = "\033[1m"
)

func printSuccess(s string) { fmt.Printf("%s%s%s\n", ColorGreen, s, ColorReset) }
func printError(s string)   { fmt.Printf("%s%s%s\n", ColorRed, s, ColorReset) }
func printInfo(s string)    { fmt.Printf("%s%s%s\n", ColorBlue, s, ColorReset) }

// --- 文件与数据持久化逻辑 ---

func ensureDataDir() {
	if _, err := os.Stat(DataDir); os.IsNotExist(err) {
		os.Mkdir(DataDir, 0755)
	}
}

func loadConfig() AppConfig {
	config := AppConfig{LastFilename: DefaultFile}
	bytes, err := os.ReadFile(filepath.Join(DataDir, ConfigFile))
	if err == nil {
		json.Unmarshal(bytes, &config)
	}
	return config
}

func saveConfig(filename string) {
	config := AppConfig{LastFilename: filename}
	bytes, _ := json.MarshalIndent(config, "", "  ")
	os.WriteFile(filepath.Join(DataDir, ConfigFile), bytes, 0644)
}

func loadStats() map[string]QuestionStat {
	stats := make(map[string]QuestionStat)
	bytes, err := os.ReadFile(filepath.Join(DataDir, StatsFile))
	if err == nil {
		json.Unmarshal(bytes, &stats)
	}
	return stats
}

func saveStats(stats map[string]QuestionStat) {
	bytes, _ := json.MarshalIndent(stats, "", "  ")
	os.WriteFile(filepath.Join(DataDir, StatsFile), bytes, 0644)
}

// --- 解析逻辑 ---

func parseFile(filename string) ([]Question, error) {
	file, err := os.Open(filename)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	var questions []Question
	var currentQ *Question

	reQuestion := regexp.MustCompile(`^(\d+)\.\s*(.*)`)
	reOption := regexp.MustCompile(`^-\s*\[([ xX])\]\s*([A-Z])\.\s*(.*)`)

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := strings.TrimSpace(scanner.Text())
		if line == "" {
			continue
		}

		if matches := reQuestion.FindStringSubmatch(line); len(matches) > 0 {
			if currentQ != nil && len(currentQ.Options) > 0 {
				questions = append(questions, *currentQ)
			}
			cleanContent := strings.ReplaceAll(matches[2], "~", " ")
			currentQ = &Question{
				OriginalIndex: matches[1],
				Content:       cleanContent,
				Options:       make([]Option, 0),
			}
			continue
		}

		if matches := reOption.FindStringSubmatch(line); len(matches) > 0 && currentQ != nil {
			isCorrect := strings.ToLower(matches[1]) == "x"
			cleanText := strings.ReplaceAll(matches[3], "~", " ")
			currentQ.Options = append(currentQ.Options, Option{
				Label: matches[2], Text: cleanText, IsKey: isCorrect,
			})
		}
	}
	if currentQ != nil && len(currentQ.Options) > 0 {
		questions = append(questions, *currentQ)
	}
	return questions, scanner.Err()
}

// --- 智能选题算法 ---

func smartSelectQuestions(qs []Question, stats map[string]QuestionStat, targetCount int) []Question {
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	for i := range qs {
		stat, exists := stats[qs[i].Content]
		weight := 0.0
		if !exists || stat.ShownCount == 0 {
			weight = 1000.0 // 新题优先
		} else {
			failRate := 1.0 - (float64(stat.CorrectCount) / float64(stat.ShownCount))
			weight = 10.0 + (failRate * 100.0) // 错题权重高
		}
		randomFactor := r.Float64() + 0.5
		qs[i].TempWeight = weight * randomFactor
	}
	sort.Slice(qs, func(i, j int) bool {
		return qs[i].TempWeight > qs[j].TempWeight
	})
	if targetCount > len(qs) {
		targetCount = len(qs)
	}
	return qs[:targetCount]
}

// --- 核心工具：处理多选输入 ---

// 获取题目的正确答案字符串，如 "ACD"
func getCorrectAnswerStr(q Question) string {
	var parts []string
	for _, opt := range q.Options {
		if opt.IsKey {
			parts = append(parts, opt.Label)
		}
	}
	sort.Strings(parts)
	return strings.Join(parts, "")
}

// 清洗并标准化用户输入
// 输入 "1 2", "a,b", "A B" -> 输出 "AB"
// 输入 "1 3" -> 输出 "AC"
func normalizeInput(input string) string {
	input = strings.ToUpper(input)
	// 替换数字为字母
	replacer := strings.NewReplacer(
		"1", "A", "2", "B", "3", "C", "4", "D",
		"5", "E", "6", "F", "7", "G", "8", "H",
	)
	input = replacer.Replace(input)

	// 提取唯一有效字符并排序
	seen := make(map[string]bool)
	var parts []string
	for _, char := range input {
		s := string(char)
		if s >= "A" && s <= "Z" {
			if !seen[s] {
				seen[s] = true
				parts = append(parts, s)
			}
		}
	}
	sort.Strings(parts)
	return strings.Join(parts, "")
}

// --- 主程序 ---

func main() {
	ensureDataDir()
	config := loadConfig()
	stats := loadStats()

	reader := bufio.NewReader(os.Stdin)

	fmt.Printf("%s=== 智能刷题终端 (支持多选) ===%s\n", ColorBold, ColorReset)
	fmt.Printf("默认题库: %s%s%s (回车使用, 或输入新路径)\n> ", ColorYellow, config.LastFilename, ColorReset)

	inputFilename, _ := reader.ReadString('\n')
	inputFilename = strings.TrimSpace(inputFilename)
	if inputFilename == "" {
		inputFilename = config.LastFilename
	}

	questions, err := parseFile(inputFilename)
	if err != nil {
		printError(fmt.Sprintf("读取失败: %v", err))
		return
	}
	if len(questions) == 0 {
		printError("文件中未找到有效题目。")
		return
	}
	saveConfig(inputFilename)

	fmt.Printf("已加载 %d 道题目。历史数据记录了 %d 道题。\n", len(questions), len(stats))
	fmt.Print("输入刷题数量 (默认全部): ")
	countStr, _ := reader.ReadString('\n')
	countStr = strings.TrimSpace(countStr)
	targetCount := len(questions)
	if n, err := strconv.Atoi(countStr); err == nil && n > 0 && n < targetCount {
		targetCount = n
	}

	examSet := smartSelectQuestions(questions, stats, targetCount)
	fmt.Printf("已生成 %d 道题目。支持输入 '12' 或 'AB' 作答多选题。\n", len(examSet))
	fmt.Println(strings.Repeat("-", 50))

	sessionCorrect := 0
	// 创建局部随机数生成器，避免每次都在循环里 NewSource 可能会有性能损耗（虽然微乎其微）
	rng := rand.New(rand.NewSource(time.Now().UnixNano()))
	for i, q := range examSet {
		// --- [新增] 选项打乱核心逻辑 ---
		// 1. 打乱选项顺序
		rng.Shuffle(len(q.Options), func(i, j int) {
			q.Options[i], q.Options[j] = q.Options[j], q.Options[i]
		})

		// 2. 重新分配标签 (A, B, C...)
		// 必须重置 Label，否则选项顺序变了但标签还是乱的（如 C. 变成了第一项）
		for k := range q.Options {
			q.Options[k].Label = string(rune('A' + k))
		}
		// -----------------------------

		// 3. 获取题目类型和正确答案 (注意：必须在打乱并重置 Label 后获取)
		correctStr := getCorrectAnswerStr(q)
		isMulti := len(correctStr) > 1
		typeLabel := "[单选题]"
		if isMulti {
			typeLabel = fmt.Sprintf("%s[多选题]%s", ColorCyan, ColorReset)
		}

		// 4. 显示题目 (已修复上一轮提到的 fmt.Printf 报错)
		stat := stats[q.Content]
		statStr := fmt.Sprintf("(历史: %d胜/%d场)", stat.CorrectCount, stat.ShownCount)
		if stat.ShownCount == 0 {
			statStr = "(新题)"
		}

		fmt.Printf("%s[%d/%d]%s %s %s %s%s%s\n",
			ColorBold, i+1, len(examSet), ColorReset,
			typeLabel,
			q.Content,
			ColorYellow, statStr, ColorReset)

		// 5. 显示选项
		for _, opt := range q.Options {
			fmt.Printf("   %s. %s\n", opt.Label, opt.Text)
		}

		// 6. 答题与验证
		answeredCorrectly := false
		for {
			fmt.Print("👉 答案: ")
			ansRaw, _ := reader.ReadString('\n')
			ansRaw = strings.TrimSpace(ansRaw)

			if strings.ToUpper(ansRaw) == "EXIT" {
				goto END_SAVE
			}

			userAns := normalizeInput(ansRaw)

			if userAns != "" {
				if userAns == correctStr {
					printSuccess("✔ Accepted")
					sessionCorrect++
					answeredCorrectly = true
				} else {
					if isMulti {
						fmt.Printf("%s✘ Wrong Answer%s (正确答案: %s)\n", ColorRed, ColorReset, correctStr)
					} else {
						fmt.Printf("%s✘ Wrong Answer%s (正确: %s)\n", ColorRed, ColorReset, correctStr)
					}
				}
				break
			}
		}

		// 更新统计
		s := stats[q.Content]
		s.ShownCount++
		if answeredCorrectly {
			s.CorrectCount++
		}
		stats[q.Content] = s

		fmt.Println(strings.Repeat("-", 40))
	}

END_SAVE:
	saveStats(stats)
	fmt.Println()
	printInfo("=== 结束 & 数据已保存 ===")
	if len(examSet) > 0 {
		rate := float64(sessionCorrect) / float64(len(examSet)) * 100
		fmt.Printf("本次得分: %d/%d (%.1f%%)\n", sessionCorrect, len(examSet), rate)
	}
}
