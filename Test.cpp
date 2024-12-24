#include <bits/stdc++.h>
using namespace std;
int main() {
    string sout = {""}; //放入程序输出文件路径
    if (!sout.size()) {
        cout << "请输入与Code.out文件对拍的路径:"<<endl;
        cin>>sout;
    }
    ifstream Ffout,Tfout;
    Tfout.open(sout, ios::in);
    Ffout.open("Code.out",ios::in);
    string s;
    int t = 1;
    bool flag = true;
    while(Tfout>>s){
        string s1;
        Ffout >> s1;
        if(s1 != s) {
            cout<<"在"<<t<<"行与正确答案不符"<<endl;
            flag = false;
        }
        t++;
    }
    if (flag) cout<<"宝宝好棒，程序输出正确"<<endl;
    Tfout.close();
    Ffout.close();
    return 0;
}