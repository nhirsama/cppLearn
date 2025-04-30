#include <bits/stdc++.h>
using i32 = int;
using pii = std::pair<i32, i32>;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i32> w(n + 1);
    std::vector tr(n + 1, std::vector<int>());
    std::vector<bool> dp(n + 1, true);  // Assume all nodes are beautiful initially
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }
    for (int i = 1; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }

    // First DFS to calculate dp values assuming node 1 is the root
    auto dfs = [&](auto &&self, int v, int f)-> void {
        for (auto i: tr[v]) {
            if (i == f) continue;
            self(self, i, v);
        }
        dp[v] = true;
        for (auto i: tr[v]) {
            if (i == f) continue;
            if (w[i] * 2 < w[v]) {
                dp[v] = false;  // If any child doesn't satisfy the condition, root is not beautiful
            }
        }
    };
    dfs(dfs, 1, -1);

    int ans = 0;
    // Second DFS to count the number of beautiful nodes
    auto dfs2 = [&](auto &&self, int v, int f)-> void {
        bool original_v_dp = dp[v];  // Save the current dp[v]
        bool original_f_dp = dp[f];  // Save the current dp[f]

        // Propagate dp state from parent to child
        dp[v] = dp[f];
        if (w[f] * 2 < w[v]) {
            dp[v] = false;  // If the parent's weight doesn't satisfy the condition, node is not beautiful
        }

        if (dp[v]) {
            ans++;  // Count the current node as a beautiful node if it satisfies the condition
        }

        for (auto i: tr[v]) {
            if (i == f) continue;
            self(self, i, v);
        }

        // Restore dp states after processing all children
        dp[v] = original_v_dp;
        dp[f] = original_f_dp;
    };

    dfs2(dfs2, 1, -1);
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