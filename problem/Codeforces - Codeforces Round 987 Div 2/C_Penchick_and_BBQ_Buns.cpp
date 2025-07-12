//  C. Penchick and BBQ Buns
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    if (n & 1) {
        if (n < 27) {
            std::cout << -1 << endl;
            return;
        } else {
            std::cout << "1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2 ";
            for (i32 i = 28; i <= n; i++) {
                std::cout << i / 2 + 1 << ' ';
            }
            std::cout << endl;
        }
    } else {
        for (i32 i = 0; i < n; i++) {
            std::cout << i / 2 + 1 << ' ';
        }
        std::cout << endl;
        return;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}