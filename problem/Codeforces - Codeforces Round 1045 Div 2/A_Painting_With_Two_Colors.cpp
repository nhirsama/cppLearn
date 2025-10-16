//  A. Painting With Two Colors
//  16:18
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int64 a, x, y;
    std::cin >> a >> x >> y;
    if (y >= x) {
        if (a % 2 == y % 2) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    } else {
        if (a % 2 == x % 2 && y % 2 == a % 2) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}
