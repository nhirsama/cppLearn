//  E - A Path in A Dictionary
//  下午11:34
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    int64 n, m, x, y;
    std::cin >> n >> m >> x >> y;
    x--, y--;
    std::vector g(n, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back({v});
        g[v].push_back({u});
    }
    for (auto &i: g) {
        std::ranges::sort(i);
    }
    std::vector<bool> vis(n);
    std::vector<int> cnt(n);
    std::stack<int> ans;
    vis[x] = true;
    auto dfs = [&](auto &&self, int u) {
        if (u == y) {
//            ans.push(u);
            return true;
        }
        for (int i = 0; i < g[u].size(); i++) {
            if (vis[g[u][i]]) continue;
            vis[g[u][i]] = true;
            if (self(self, g[u][i])) {
                ans.push(g[u][i]);
                return true;
            };
        }
        return false;
//        if (!vis[u] && cnt[u] < g[u].size()) {
//            vis[u] = true;
//            ans.push_back(g[u][cnt[u]][0]);
//            self(g[u][cnt[u]++][0]);
//        }
    };
    dfs(dfs, x);
    ans.push(x);
    while (!ans.empty()) {
        std::cout << ans.top() + 1 << ' ';
        ans.pop();
    }
    std::cout << endl;
//    for (auto i: ans) {
//        std::cout << i << ' ';
//    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    if (OJ_NAME != "AtCoder")
    std::cin >> T;
    while (T--) nhir();
    return 0;
}