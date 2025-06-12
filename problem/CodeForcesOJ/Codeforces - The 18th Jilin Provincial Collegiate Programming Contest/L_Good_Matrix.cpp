//  L. Good Matrix
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 998244353;
constexpr char endl = '\n';

int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    //i32 po = (std::max(m, n) + 1 - std::min(n, m)) * std::min(n, m) % mod;
    if (n % 2 == 0 && m % 2 == 0) {
        std::cout << power(2, 0, mod) << endl;
    } else if (n % 2 == 0) {
        std::cout << power(2, n - 1, mod) << endl;
    } else if (m % 2 == 0) {
        std::cout << power(2, m - 1, mod) << endl;

    } else std::cout << power(2, n + m - 2, mod) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}