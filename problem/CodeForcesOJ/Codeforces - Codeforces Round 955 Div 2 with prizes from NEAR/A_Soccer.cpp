//  A. Soccer
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (x2 > y2) {
        std::cout << (x1 < y1 ? "NO\n" : "YES\n");
    } else {
        std::cout << (y1 < x1 ? "NO\n" : "YES\n");
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}