#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
static constexpr i64 mod=998244353;
i64 qpow(i64 a,i64 b){
    i64 ans=1;
    while(b){
        if(b&1){
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b=b>>1;

    }
    return ans;
}
const int maxn=500000;
std::vector<i64> fact(maxn+10),invfact(maxn+10);
void solve(){
    std::vector<int> c(26);
    int sum=0;
    for(int i=0;i<26;i++){
        std::cin>>c[i];
        sum+=c[i];
    }
    int n=sum;
    int odd=(n%2==0)?n/2:(n+1)/2;
    int even=n-odd;
    std::vector<int> a;
    for(int i=0;i<26;i++){
        if(c[i]>0){
            a.emplace_back(c[i]);
        }
    }
    std::vector<int> dp(odd+1,0),nxt(odd+1,0);
    dp[0]=1;
    for(int x:a){
        fill(nxt.begin(),nxt.end(),0);
        for(int j=0;j<=odd;j++){
            if(dp[j]!=0){
                nxt[j]=(nxt[j]+dp[j])%mod;
                if(j+x<=odd){
                    nxt[j+x]=(nxt[j+x]+dp[j])%mod;
                }
            }
        }
        dp.swap(nxt);
    }
    int v=dp[odd]%mod;
    i64 w=(fact[odd]*fact[even])%mod;
    i64 dd=1;
    for(int i=0;i<26;i++){
        dd=(dd*fact[c[i]])%mod;
    }
    w=w*qpow(dd,mod-2)%mod;
    i64 ans=w*v%mod;
    std::cout<<ans<<endl;

}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    std::cin>>t;
    std::cout<<(t&31)<<endl;
    return 0;
}

