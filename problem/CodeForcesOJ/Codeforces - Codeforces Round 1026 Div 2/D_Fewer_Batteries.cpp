//  D. Fewer Batteries
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
using pii = std::pair<i32, i32>;
constexpr i32 inf = 4e18;

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector<std::vector<pii> > g(n);
    for (i32 i = 0; i < m; i++) {
        i32 u, vv, w;
        std::cin >> u >> vv >> w;
        u--, vv--;
        g[u].push_back({vv, w});
    }
    std::vector<i32> dp(n, 0x3f3f3f3f3f3f3f3fll), dp2(n, 0x3f3f3f3f3f3f3f3fll);
    dp[n - 1] = dp2[n - 1] = 0;
    for (int u = n - 2; ~u; u--) {
        for (auto &[vv,w]: g[u]) {
            if (dp[vv] == 0x3f3f3f3f3f3f3f3fll) continue;
            i64 aa = std::max(std::max(w, dp[vv]) - v[u], 0ll);
            i64 bb = std::max(dp2[vv], std::max(w, dp[vv]));
            if (aa < dp[u] || (aa == dp[u] && bb < dp2[u])) {
                dp[u] = aa;
                dp2[u] = bb;
            }
        }
    }

    if (dp[0] >= 0x3f3f3f3f3f3f3f3fll / 2) {
        std::cout << -1 << endl;
    } else {
        std::cout << dp2[0] << endl;
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
