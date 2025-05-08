//  P3931 SAC E#1 - 一道难题 Tree
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using pii = std::pair<i32, i32>;

void nhir() {
    i32 n, root;
    std::cin >> n >> root;
    root--;
    std::vector tree(n, std::vector<pii>());
    for (i32 i = 1; i < n; i++) {
        i32 a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }
    std::vector<i32> dp(n, 0);
    auto dfs = [&](auto &&self, int u, int f)-> void {
        if (tree[u].size() == 1 && u != f) {
            dp[u] = 0x3f3f3f3f3f3f3f3f;
        }
        for (auto [v,w]: tree[u]) {
            if (v == f) continue;
            self(self, v, u);
            dp[u] += std::min(dp[v], w);
        }
    };
    dfs(dfs, root, root);
    std::cout << dp[root] << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
