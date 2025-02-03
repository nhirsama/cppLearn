//B. Normal Problem
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
void Func(){
    string s;
    cin>>s;
    string ans;
    for(int i=s.size()-1;~i;i--){
        if(s[i]=='q'){ans.push_back('p');}
        else if(s[i]=='p'){ans.push_back('q');}
        else ans.push_back(s[i]);

    }
    cout<<ans<<endl;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
