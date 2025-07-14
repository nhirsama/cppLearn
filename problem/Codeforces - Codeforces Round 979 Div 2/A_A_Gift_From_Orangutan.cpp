//  A. A Gift From Orangutan
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    i32 max = 0, min = inf_i64;
    for (i32 i = 0; i < n; i++) {
        i32 t;
        std::cin >> t;
        max = std::max(max, t);
        min = std::min(min, t);
    }
    std::cout << (max - min) * (n - 1) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}