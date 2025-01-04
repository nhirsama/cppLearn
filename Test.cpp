#include <bits/stdc++.h>
namespace fs = std::filesystem;

void Test(const fs::path &correctFile, const fs::path &inputFile = "Code.out");

int main() {
    const clock_t beginTime = clock();
    fs::path outPath; //放入程序输出文件路径
    if (outPath.empty()) {
        std::ifstream ifile;
        ifile.open("Testlib.out");
        std::string line;
        ifile >> line;
        //可以在Testlib.out中输入正确答案的文件相对路径，或者输入正确答案。
        if (line.empty()) {
            std::cout << "请输入与Code.out文件对拍的路径:" << std::endl;
            std::cin >> outPath;
        } else {
            if (line.substr(0, 13) == "inAndoutFile/") outPath = line;
            else outPath = "Testlib.out";
        }
        ifile.close();
    }
    Test(outPath);
    const clock_t endTime = clock();
    std::cout << "本程序运行时间为" << static_cast<double>(endTime - beginTime) << "毫秒" << std::endl;
    return 0;
}

//将inputFile与correctFile对拍。
void Test(const fs::path &correctFile, const fs::path &inputFile) {
    std::ifstream CFOut, IFOut;
    CFOut.open(correctFile, std::ios::in);
    IFOut.open(inputFile, std::ios::in);
    std::string s;
    int t = 1;
    bool flag = true;
    while (getline(CFOut, s)) {
        std::string s1;
        if (!getline(IFOut, s1)) {
            std::cout << "程序输出过短，再重新检查一遍吧" << std::endl;
            flag = false;
            break;
        }
        if (s1 != s) {
            std::cout << "在" << t << "行与正确答案不符" << std::endl;
            flag = false;
        }
        t++;
    }
    //若IFOut输入流不为空，则证明对拍
    if (IFOut >> s) std::cout << "程序输出过长，再重新检查一下吧" << std::endl;
    else if (flag) std::cout << "宝宝好棒，程序输出正确" << std::endl;
    IFOut.close();
    CFOut.close();
}
