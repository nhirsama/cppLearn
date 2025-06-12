//  D. Retaliation
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    i32 d = v[1] - v[0];
    for (i32 i = 0; i < n - 1; i++) {
        if (v[i + 1] - v[i] != d) {
            std::cout << "NO\n";
            return;
        }
    }
    i32 num = v[0] + n * d;
    if (num < 0 || num % (n + 1)) {
        std::cout << "NO\n";
        return;
    }
    if (num / (n + 1) - d < 0) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
