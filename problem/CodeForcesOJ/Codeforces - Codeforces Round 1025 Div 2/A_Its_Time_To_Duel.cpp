//  A. It's Time To Duel
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    if (std::ranges::count(v, 1) == n) {
        std::cout << "YES\n";
        return;
    }
    for (i32 i = 0; i < n - 1; i++) {
        if (v[i] == 0 && v[i + 1] == 0) {
            std::cout << "YES\n";
            return;
        }
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