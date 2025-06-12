//  E - Pair Annihilation
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
using arr2 = std::array<i32, 2>;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> a(n);
    for (auto &i: a)std::cin >> i;
    std::vector g(n, std::vector<arr2>());
    for (i32 i = 1; i < n; i++) {
        i32 u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    std::vector<i32> dp(n);
    i32 ans = 0;
    auto dfs = [&](auto &&self, i32 u, i32 f)-> void {
        for (auto &[v,w]: g[u]) {
            if (v == f) continue;
            self(self, v, u);
            dp[u] += dp[v];
            ans += std::abs(dp[v]) * w;
        }
        dp[u] += a[u];
    };
    dfs(dfs, 0, 0);
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) nhir();
    return 0;
}
