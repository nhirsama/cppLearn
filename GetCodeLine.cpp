#include <bits/stdc++.h>

namespace fs = std::filesystem;

int GetFileLine(const fs::path &path);

int dfs(const fs::path &inputPath);

void printAllFile(fs::path &inputPath);

int main() {
    // 指定要遍历的文件夹路径
    fs::path folderPath = "./";
    printAllFile(folderPath);
    int t = 0;
    // 检查文件夹是否存在
    if (!fs::exists(folderPath)) {
        std::cerr << "未找到相关文件夹" << std::endl;
        return 1;
    }
    // 遍历文件夹中的所有文件
    t += dfs(folderPath);
    std::cout << t << std::endl;
    return 0;
}

//使用深搜遍历目录树的每一个文件
int dfs(const fs::path &inputPath) {
    int t = 0;
    if (!fs::is_directory(inputPath)) {
        t += GetFileLine(inputPath);
    } else {
        for (const auto &entry: fs::directory_iterator(inputPath)) {
            const auto &path = entry.path();
            t += dfs(path);
        }
    }
    return t;
}

//统计代码行数
int GetFileLine(const fs::path &path) {
    int t = 0;
    std::ifstream ifs;
    ifs.open(path.string(), std::ios::in);
    std::string line;
    while (getline(ifs, line)) t++;
    ifs.close();
    return t;
}

//打印路径中所有的文件
void printAllFile(fs::path &inputPath) {
    int t = 1;
    for (const auto &entry: fs::directory_iterator(inputPath)) {
        //如果文件夹或文件以'.'起始，则排除。
        if (entry.path().filename().string().substr(0, 1) == ".") continue;
        //如果文件以".exe"结尾，则排除。
        if (entry.path().extension() == ".exe") continue;
        std::cout << t++ << '.' << entry.path().filename() << std::endl;
    }
    int m = 1;
    std::cout << "请输入要遍历的文件夹或文件编号:" << std::endl;
    std::cin >> t;
    for (const auto &entry: fs::directory_iterator(inputPath)) {
        //如果文件夹或文件以'.'起始，则排除。
        if (entry.path().filename().string().substr(0, 1) == ".") continue;
        //如果文件以".exe"结尾，则排除。
        if (entry.path().extension() == ".exe") continue;
        if (m++ == t) {
            inputPath = entry.path();
            break;
        }
    }
    std::cout << inputPath << std::endl;
}
