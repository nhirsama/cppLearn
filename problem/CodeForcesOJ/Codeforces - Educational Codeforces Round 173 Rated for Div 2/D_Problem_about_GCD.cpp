//  D. Problem about GCD
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i64 n,m,k;
    std::cin>>n>>m>>k;
    if(m<k){
        std::cout<<"-1 -1\n";
        return;
    }
    i64 nn = n<=k ? 1 : n/k+(n%k!=0);
    i64 nm = m/k;
    for(i64 len = nm-nn;~len;len--){
        for(i64 l = nn;l+len<=nm;l++){
            if(std::gcd(l,l+len) == 1){
                std::cout<<k*l<< ' '<<k*(l+len)<<endl;
                return;
            }
        }
    }
    std::cout<<"-1 -1\n";
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}