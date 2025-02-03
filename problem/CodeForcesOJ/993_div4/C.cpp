#define LOCAL
//C. Hard Problem
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
void Func(){
    int m,a,b,c;
    cin>>m>>a>>b>>c;
    int ans=0;
    if(a>m) a = m;
    if(b>m) b = m;
    ans+=min(a+b+c,2*m);

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
