//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long Func(long long x){
    if (x == 0) return 0;
    if(x==1) return 1;
    long long aa = 1;
    long long bb = 1;
    while (x>aa) {
        aa<<=1;
        bb++;
    }
    return bb%mod;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    long long t;
    cin>>t;
    long long ans = 0;
    long long i = 0;
    while((1ll<<i)<=t) {
        i++;
    }
    i--;
    ans += Func(t)%mod*((t-(1ll<<i))%mod);
    i--;
    for (;~i;i--) {
        ans += Func(2ll<<i)%mod*(((2ll<<i)-(1ll<<i))%mod);
        ans %= mod;
    }
    ans += Func(1);
    //ans +=
    ans %= mod;
    cout<<ans<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}