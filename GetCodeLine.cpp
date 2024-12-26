#include <bits/stdc++.h>

namespace fs = std::filesystem;

int GetFileLine(const fs::path& path);
int dfs(const fs::path& inputPath);

int main() {
    // 指定要遍历的文件夹路径
    fs::path folderPath = "problem";
    int t = 0;
    // 检查文件夹是否存在
    if (!fs::exists(folderPath)) {
        std::cerr << "未找到相关文件夹" << std::endl;
        return 1;
    }
    // 遍历文件夹中的所有文件
    t += dfs(folderPath);
    std::cout << t<<std::endl;
    return 0;
}
//使用深搜遍历目录树的每一个文件
int dfs(const fs::path& inputPath) {
    int t = 0;
    if (!fs::is_directory(inputPath)) {
        t += GetFileLine(inputPath);
    }
    else {
        for (const auto& entry : fs::directory_iterator(inputPath)) {
            const auto& path = entry.path();
            t += dfs(path);
        }
    }
    return t;
}
//统计代码行数
int GetFileLine(const fs::path& path) {
    int t = 0;
    std::ifstream ifs;
    ifs.open(path.string(), std::ios::in);
    std::string line;
    while (getline(ifs, line)) t++;
    ifs.close();
    return t;
}