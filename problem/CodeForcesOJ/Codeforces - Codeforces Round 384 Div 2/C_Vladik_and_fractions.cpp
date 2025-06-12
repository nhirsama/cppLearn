//  C. Vladik and fractions
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    if (n + 1 == n * n + n || n == n * n + n) {
        std::cout << -1 << endl;
        return;
    }
    std::cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}