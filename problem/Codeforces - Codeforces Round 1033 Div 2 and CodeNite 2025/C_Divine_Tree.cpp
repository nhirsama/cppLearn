//  C. Divine Tree
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    if (m < n || m > (n * (1 + n) / 2)) {
        std::cout << -1 << endl;
        return;
    }
    i32 t = n;
    if (m <= 2 * n - 1) {
        std::cout << m - (n - 1) << endl;
        t = m - (n - 1);
        for (i32 i = 1; i <= n; i++) {
            if (i == t) continue;
            if (i == 1) {
                std::cout << t << ' ' << i << endl;
                continue;
            }
            std::cout << 1 << ' ' << i << endl;
        }
        return;
    }
    std::cout << n << endl;
    m -= n;
    while (--n) {
        if (n == 1) {
            std::cout << 1 << ' ' << t << endl;
        } else if (m >= n + n - 1) {
            std::cout << t << ' ' << n << endl;
            m -= n;
        } else {
            std::cout << 1 << ' ' << n << endl;
            m--;
        }
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
