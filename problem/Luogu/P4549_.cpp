//  P4549 【模板】裴蜀定理
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
    i32 n;
    std::cin>>n;
    std::vector<i32> g(n);
    for(auto &i:g) std::cin>>i;
    i32 gcd = std::abs(g[0]);
    for(auto i:g) gcd = std::gcd(gcd,std::abs(i));
    std::cout<<gcd<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}