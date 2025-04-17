//  H. La Vaca Saturno Saturnita
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
    i32 n,q;
    std::cin>>n;
    std::vector<i32> ai(n);
    for(auto &i:ai) std::cin>>i;
    std::map<i32,std::vector<i32>> m;
    for(i32 i = 0;i<n;i++){
        m[ai[i]].push_back(i);
    }
    
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}