//P10446 64位整数乘法
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    long long a,b,p;
    cin>>a>>b>>p;
    long long ans = 0;
    while(b){
        if(b&1) (ans+=a) %=p;
        b>>=1;
        (a+=a) %=p;
    }
    cout<<ans<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}