//  A - Coprime Pair
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
    i64 n,m;
    std::cin>>n>>m;
    for(i64 len = m-n;~len;len--){
        for(i64 l = n;l+len<=m;l++){
            if(std::gcd(l,l+len) == 1){
                std::cout<<len<<endl;
                return;
            }
        }
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}