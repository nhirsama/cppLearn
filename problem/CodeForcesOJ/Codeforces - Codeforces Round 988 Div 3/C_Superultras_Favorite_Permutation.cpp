//  C. Superultra's Favorite Permutation
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
    if (n < 5) {
        std::cout << -1 << endl;
        return;
    } else {
        for (i32 i = 2; i <= n; i += 2) {
            if (i == 4) continue;
            std::cout << i << ' ';
        }
        std::cout << "4 5 ";
        for (i32 i = 1; i <= n; i += 2) {
            if (i == 5) continue;
            std::cout << i << ' ';
        }
    }
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}