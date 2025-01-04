#define LOCAL
//T549853 「Cfz Round 5」Non-breath Oblige
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
long long n,s,t;
long long answer = 0;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--) {
        cin>>n>>s>>t;
        long long aa = (static_cast<long long>(pow(2, n))-1);
        if ((s | t) == aa) cout << (s^t) << endl;
        else if (s == t) cout << 0 << endl;
        else cout << (aa^s)+(aa^t) << endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}