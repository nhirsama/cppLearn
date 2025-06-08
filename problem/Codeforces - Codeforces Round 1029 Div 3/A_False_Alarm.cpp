//  A. False Alarm
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, x;
    std::cin >> n >> x;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    i32 l = -1, r = -1;
    for (i32 i = 0; i < n; i++) {
        if (v[i] == 1) {
            if (l == -1) l = i;
            r = i;
        }
    }
    if (r - l + 1 <= x) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
