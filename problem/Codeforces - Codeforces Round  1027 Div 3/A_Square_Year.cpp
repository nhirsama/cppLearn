//  A. Square Year
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    i32 t = std::sqrt(n);
    if (t * t == n) {
        std::cout << 0 << ' ' << t << endl;
    } else std::cout << -1 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
