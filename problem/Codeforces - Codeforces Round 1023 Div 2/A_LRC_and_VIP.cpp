//  A. LRC and VIP
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

void nhir() {
    i32 n;
    std::cin>>n;
    std::vector<i32> v(n);
    for (auto &i:v) std::cin>>i;
    auto max = *std::ranges::max_element(v);
    if (max == *std::ranges::min_element(v)) {
        std::cout<<"No\n";
        return;
    }
    std::cout<<"Yes\n";
    for (auto i:v) {
        std::cout<<(i == max ? 1 : 2)<< ' ';
    }
    std::cout<<endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}