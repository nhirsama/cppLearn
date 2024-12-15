#include <iostream>
using namespace std;
const int mod = 1e9+7;
unsigned long long fact(int n){
    if(n == 0) return 1;
    n%=mod;
    unsigned long long ans = 1;
    for(int i = 1;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    return ans;
}
int main() {
    unsigned long long ans = 0;
    int n;
    cin>>n;
    if(n&1){
        n--;
    }
    unsigned long long a = fact(n);
    ans = 1ll*a%mod*a*(n/2+1)%mod;
    cout<<ans<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")