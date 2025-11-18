//  Bitwise Perfect
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
    std::vector<i32> v(n);
    for (i32 &i: v)std::cin >> i;
    if (n > 60) {
        std::cout << "NO\n";
        return;
    } else {
        for (i32 i = 0; i < n; i++) {
            for (i32 j = i + 1; j < n; j++) {
                if (i == j) continue;
                if (std::max(v[i], v[j]) >= (v[i] ^ v[j])) {
                    std::cout << "NO\n";
                    return;
                }
            }
        }
    }
    std::cout << "YES\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}