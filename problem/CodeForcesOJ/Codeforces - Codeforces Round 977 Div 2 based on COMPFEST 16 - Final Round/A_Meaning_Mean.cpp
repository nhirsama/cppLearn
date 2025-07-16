//  A. Meaning Mean
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (i32 &i: v) std::cin >> i;
    std::ranges::sort(v);
    i32 b = (v[0] + v[1]) / 2;
    for (i32 i = 2; i < n; ++i)b = (b + v[i]) / 2;
    std::cout << b << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
