#define LOCAL
//P1029 [NOIP2001 普及组] 最大公约数和最小公倍数问题
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int gcd_u(int a,int b) {
    return b==0?a:gcd_u(b,a%b);
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int ans = 0;
    int flag = 0;
    long long x,y,n;
    cin>>x>>y;
    n=x*y;
    for(int i = 2;i<=sqrt(n);i++){
        if(n%i)continue;
        int m = n/i;
        if(gcd_u(i,m) == x) {
            ans++;
            if(i == m) flag = 1;
        }
    }
    cout<<ans*2-flag<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}