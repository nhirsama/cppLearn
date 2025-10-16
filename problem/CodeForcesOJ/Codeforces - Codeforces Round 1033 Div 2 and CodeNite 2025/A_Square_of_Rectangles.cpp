//  A. Square of Rectangles
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 a1, a2, a3, b1, b2, b3;
    std::cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    for (i32 i = 0; i < 2; i++) {
        if (a1 == a2 && a2 == a3 && b1 + b2 + b3 == a1) {
            std::cout << "YES\n";
            return;
        } else if (a1 == a2 + a3 && a1 == b1 + b2 && a1 == b1 + b3) {
            std::cout << "YES\n";
            return;
        }
        std::swap(a1, b1);
        std::swap(a2, b2);
        std::swap(a3, b3);
    }
    std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}