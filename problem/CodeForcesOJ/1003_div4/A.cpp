//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
void Func(){
    string s;
    cin>>s;
    if(s.size()>=2 &&s.substr(s.size()-2) == "us"){
        s.erase(s.size()-2);
        s+="i";
        cout<<s<<endl;
    }
    else if(s.substr(s.size()-1) == "i"){
        s.erase(s.size()-1);
        s+="us";
        cout<<s<<endl;
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
