#include <bits/stdc++.h>
using i32 = int;
using pii = std::pair<i32, i32>;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i32> w(n + 1);
    std::vector tr(n + 1, std::vector<int>());
    std::vector<bool> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }
    for (int i = 1; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    auto dfs = [&](auto &&self, int v, int f)-> void {
        for (auto i: tr[v]) {
            if (i == f) continue;
            self(self, i, v);
        }
        dp[v] = true;
        for (auto i: tr[v]) {
            if (i == f) continue;
            dp[v] = (w[i] * 2 >= w[v] && dp[i]);
        }
    };
    dfs(dfs, 1, 1);
    i32 ans = 0;
    auto dfs2 = [&](auto &&self, int v, int f)-> void {
        bool ft = dp[f];
        dp[f] = true;
        for (auto i: tr[f]) {
            if (i == v) continue;
            dp[f] = dp[f] && (w[i] * 2 >= w[f]) && dp[i];
            if (!dp[f]) break;
        }
        bool vt = dp[v];
        dp[v] = dp[v] && dp[f] && (w[f] * 2 >= w[v]);
        ans += dp[v];
        for (auto i: tr[v]) {
            if (i == f) continue;
            self(self, i, v);
        }
        dp[f] = ft;
        dp[v] = vt;
    };
    dfs2(dfs2, 1, 1);
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}

/*
1
4
2 2 2 2
1 1 1 1
*/
