//  Two Coins
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    std::ranges::sort(v);
    auto i = std::unique(v.begin(), v.end()) - v.begin();
    std::cout << i << endl;
    for (auto _ = 0; _ < i; _++) {
        std::cout << v[_] << ' ';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}