
//A. Easy Problem
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int n;
void Func(){
    cin>>n;
    cout<<n-1<<endl;
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
