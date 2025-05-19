//  K. Welfare
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, m, x, y;
    std::cin >> n >> m >> x >> y;
    if (y >= x) {
        std::cout << y * n + y * m << endl;
        return;
    }
    if (m == 0 && n == 0) {
        std::cout << 0 << endl;
        return;
    }

    if (n == 0) {
        std::cout << x << endl;
        return;
    }
    if (y == 0) {
        std::cout << x * ((n + m) != 0) << endl;
        return;
    }
    if (m == 0) {
        std::cout << (n - 1) * y + x << endl;
        return;
    }
    if (y == 0) {
        std::cout << x << endl;
        return;
    }
    if (x == 0) {
        std::cout << y * n + y * m << endl;
        return;
    }
    if (m == 1) {
        std::cout << x + y * n << endl;
        return;
    }
    // if (n == 1 || m == 1) {
    //     std::cout << x + y << endl;
    //     return;
    // }
    i32 t = x / y + (x % y != 0) - 1;
    if (t <= n) {
        std::cout << std::max(x + ((n - t) + m) * y, x + n * y) << endl;
        return;
    }
    std::cout << x + n * y << endl;
    //std::cout << -1 << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
