#include <bits/stdc++.h>
namespace fs = std::filesystem;

int main() {
    // 指定要遍历的文件夹路径
    fs::path folderPath = "problem";
    int t = 0;
    // 检查文件夹是否存在
    if (!fs::exists(folderPath) || !fs::is_directory(folderPath)) {
        std::cerr << "未找到相关文件夹" << std::endl;
        return 1;
    }

    // 遍历文件夹中的所有文件
    for (const auto& entry1 : fs::directory_iterator(folderPath)) {
        auto filearr = entry1.path().filename();
        std::string onepath =folderPath.string()+'/'+filearr.string();
        std::cout << filearr << std::endl;
        for (const auto& entry : fs::directory_iterator(onepath)) {
            auto SOut = entry.path().filename();
            std::ifstream ifs;
            std::string temp = onepath+'/'+SOut.std::filesystem::path::string();
            ifs.open(temp,std::ios::in);
            std::string line;
            while (ifs>>line) t++;
            ifs.close();
            std::cout << SOut << std::endl;
        }
    }
    std::cout << t<<std::endl;
    return 0;
}
