//  E. Kirei Attacks the Estate
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector g(n, std::vector<i32>());
    std::vector<i32> w(n);
    for (auto &i: w) std::cin >> i;
    for (i32 i = 1; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<std::array<i32, 2> > dp(n);
    dp[0][0] = w[0];
    dp[0][1] = -w[0];
    auto dfs = [&](this auto self, i32 u, i32 f)-> void {
        for (auto v: g[u]) {
            if (v == f) continue;
            dp[v][0] = std::max(w[v], w[v] + dp[u][1]);
            dp[v][1] = std::max(-w[v], -w[v] + dp[u][0]);
            self(v, u);
        }
    };
    dfs(0, 0);
    for (auto [x,y]: dp) {
        std::cout << x << ' ';
    }
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
