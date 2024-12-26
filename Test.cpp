#include <bits/stdc++.h>
using namespace std;

int main() {
    clock_t beginTime;
    clock_t endTime;
    beginTime = clock();
    string sout = {""}; //放入程序输出文件路径
    if (sout.empty()) {
        ifstream ifile;
        ifile.open("Testlib.out");
        string line;
        ifile >> line;
        //可以在Testlib.out中输入正确答案的文件相对路径，或者输入正确答案。
        if (line.empty()) {
            cout << "请输入与Code.out文件对拍的路径:" << endl;
            cin >> sout;
        } else {
            if (line.substr(0, 13) == "inAndoutFile/") sout = line;
            else sout = "Testlib.out";
        }
        ifile.close();
    }
    ifstream Ffout, Tfout;
    Tfout.open(sout, ios::in);
    Ffout.open("Code.out", ios::in);
    string s;
    int t = 1;
    bool flag = true;
    while (Tfout >> s) {
        string s1;
        if (!(Ffout >> s1)) {
            cout << "程序输出过短，再重新检查一遍吧" << endl;
            flag = false;
            break;
        };
        if (s1 != s) {
            cout << "在" << t << "行与正确答案不符" << endl;
            flag = false;
        }
        t++;
    }
    if (Ffout >> s) cout << "程序输出过长，再重新检查一下吧" << endl;
    else if (flag) cout << "宝宝好棒，程序输出正确" << endl;
    Tfout.close();
    Ffout.close();
    endTime = clock();
    cout << "本程序运行时间为" << static_cast<double>(endTime - beginTime) << "毫秒" << endl;
    return 0;
}
