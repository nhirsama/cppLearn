//  A. Letter Home
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, s;
    std::cin >> n >> s;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    i32 min = *std::ranges::min_element(v);
    i32 max = *std::ranges::max_element(v);
    std::cout << max - min + (std::min(std::abs(min - s), std::abs(max - s))) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
