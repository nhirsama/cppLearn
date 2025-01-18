#define LOCAL
//P5091 【模板】扩展欧拉定理
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
long long int n,m,mod;
long long pow(long long int a,long long int b){
    long long int ans = 1;
    for(;b;b>>=1){
        if(b&1){
            ans = ans%mod*(a%mod)%mod;
        }
        a*=a;
        a%=mod;
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>mod;
    n %= mod;
    long long phiM = mod,mm = mod;
    for (long long int i = 2; i <= mm/i; i++) {
        if (mm % i == 0) {
            phiM = phiM / i * (i-1);
            while (mm % i == 0) {
                mm /=i;
            }
        }
    }
    bool flag = false;
    if (mm>1) phiM=phiM/mm*(mm-1);
    char c;
    while ( (c = getchar())<'0'||c>'9') {}
    do {
        m = (m<<3)+(m<<1)+(c^'0');
        if(m>=phiM) {
            m%=phiM;
            flag = true;
        }
    }
    //byd，被自己气笑了，这行代码一开始写成while ( (c=getchar())>'0'&& c<'9');了，上面所有代码都排除了一遍，就是没想到快读写错了
    while ( (c=getchar())>='0'&& c<='9');
    if (flag) cout << pow(n,m+phiM);
    else cout<<pow(n,m);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}