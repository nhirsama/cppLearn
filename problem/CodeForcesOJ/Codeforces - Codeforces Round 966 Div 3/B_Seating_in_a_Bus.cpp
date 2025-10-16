//  B. Seating in a Bus
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<bool> vis(n + 2);
    bool ok = true;
    for (i32 i = 0; i < n; i++) {
        i32 t;
        std::cin >> t;
        if (i == 0) {
            vis[t] = true;
        } else {
            if (vis[t - 1] || vis[t + 1]) vis[t] = true;
            else {
                ok = false;
            }
        }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}