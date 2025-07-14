package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"sync"
)

// getFileLine 统计文件行数
func getFileLine(path string) int {
	file, err := os.Open(path)
	if err != nil {
		return 0
	}
	defer file.Close()

	reader := bufio.NewReader(file)
	count := 0
	for {
		_, err := reader.ReadString('\n')
		if err != nil {
			if err == io.EOF {
				break
			}
			return count
		}
		count++
	}
	return count
}

// dfs 并发遍历目录，遇到文件则统计行数
func dfs(path string, wg *sync.WaitGroup, ch chan int) {
	defer wg.Done()
	info, err := os.Stat(path)
	if err != nil {
		return
	}
	if !info.IsDir() {
		// 文件，统计行数
		lines := getFileLine(path)
		ch <- lines
		return
	}
	// 目录，遍历子项
	entries, err := os.ReadDir(path)
	if err != nil {
		return
	}
	for _, entry := range entries {
		name := entry.Name()
		// 过滤以 . 开头和 .exe 文件
		if name[0] == '.' || filepath.Ext(name) == ".exe" {
			continue
		}
		subPath := filepath.Join(path, name)
		wg.Add(1)
		go dfs(subPath, wg, ch)
	}
}

// countLinesConcurrently 启动并发统计，返回总行数
func countLinesConcurrently(root string) int {
	var wg sync.WaitGroup
	ch := make(chan int)

	wg.Add(1)
	go dfs(root, &wg, ch)

	// 关闭通道
	go func() {
		wg.Wait()
		close(ch)
	}()

	total := 0
	for cnt := range ch {
		total += cnt
	}
	return total
}

func main() {
	root := "./"
	// 列出目录下所有文件和文件夹
	entries, err := os.ReadDir(root)
	if err != nil {
		fmt.Fprintln(os.Stderr, "无法读取目录:", err)
		os.Exit(1)
	}

	valid := []os.DirEntry{}
	fmt.Println("可选文件/文件夹列表:")
	i := 1
	for _, entry := range entries {
		name := entry.Name()
		if name[0] == '.' || filepath.Ext(name) == ".exe" {
			continue
		}
		valid = append(valid, entry)
		fmt.Printf("%d. %s\n", i, name)
		i++
	}

	// 读取用户选择
	var choice int
	fmt.Print("请输入要遍历的文件夹或文件编号: ")
	if _, err := fmt.Scan(&choice); err != nil || choice < 1 || choice > len(valid) {
		fmt.Fprintln(os.Stderr, "无效的选择")
		os.Exit(1)
	}

	selected := filepath.Join(root, valid[choice-1].Name())

	// 并发统计行数
	total := countLinesConcurrently(selected)
	fmt.Println("总行数:", total)
}
