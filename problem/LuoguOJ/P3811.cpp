#define LOCAL
//P3811 【模板】模意义下的乘法逆元
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 3e6+10;
int mod = 1;
int niy[N];
// int qpow(int a,int b){
//     a%=mod;
//     int res=1;
//     while(b){
//         if(b&1){
//             res*=a;
//             res%=mod;
//         }
//         b>>=1;
//         a*=a;
//         a%=mod;
//     }
//     return res;
// }
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin>>n>>mod;
    niy[1] = 1;
    puts("1");
    for(int i=2;i<=n;i++){
        //TLE
        // int ans = qpow(i,mod-2);
        // printf("%d\n",ans%mod);
        niy[i] = 1ll*(mod-mod/i)*niy[mod%i]%mod;
        printf("%d\n",niy[i]);
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}