//  D. Coprime
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 x, y;
    std::cin >> x >> y;
    for (i32 i = x + 1; i < y; i++) {
        if (std::gcd(x, i) == 1 && std::gcd(y, i) == 1) {
            std::cout << i << endl;
            return;
        }
    }
    std::cout << -1 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}