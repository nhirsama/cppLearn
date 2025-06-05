//  P7771 【模板】欧拉路径
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
using arr2 = std::array<i32, 2>;

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector<i32> id(n);
    std::vector g(n, std::vector<arr2>());
    for (i32 i = 0; i < m; i++) {
        i32 u, v;
        std::cin >> u >> v;
        u--, v--;
        id[v]++;
        // od[u]++;
        g[u].push_back({v, i});
    }
    i32 s = -1;
    for (i32 i = 0; i < n; i++) {
        auto &adj = g[i];
        std::ranges::sort(adj);
        if (std::abs((i32) adj.size() - id[i]) > 1) {
            std::cout << "No\n";
            return;
        }
        if (adj.size() == id[i] + 1) {
            if (s != -1) {
                std::cout << "No\n";
                return;
            } else s = i;
        }
    }
    std::stack<i32> ans;
    std::vector<bool> vis(m);
    std::vector<i32> cnt(n);
    auto dfs = [&](auto &&self, i32 u)-> void {
        for (auto &[v,it]: g[u]) {
            if (vis[it]) continue;
            vis[it] = true;
            cnt[v]++;
            self(self, v);
            if (cnt[v] >= g[v].size()) break;
        }
        ans.push(u);
    };
    dfs(dfs, s == -1 ? 0 : s);
    if (ans.size() == m + 1) {
        while (!ans.empty()) {
            std::cout << ans.top() + 1 << ' ';
            ans.pop();
        }
    } else {
        std::cout << "No\n";
    }
    // i32 s = -1, t = -1;
    // for (i32 i = 0; i < n; i++) {
    //     if (id[i] == od[i]) {
    //     } else if (id[i] == od[i] + 1) {
    //         if (t == -1) t = i;
    //         else {
    //             std::cout << "No\n";
    //             return;
    //         }
    //     } else if (id[i] + 1 == od[i]) {
    //         if (s == -1) s = i;
    //         else {
    //             std::cout << "No\n";
    //             return;
    //         }
    //     } else {
    //         std::cout << "No\n";
    //         return;
    //     }
    // }
    // if (s == -1 && t == -1) s = 0;
    // std::vector<i32> ans;
    // ans.push_back(s);
    // std::vector<bool> vis(m);
    // auto dfs = [&](auto &&self, i32 u)-> void {
    //     std::ranges::sort(g[u]);
    //     for (auto [v,t]: g[u]) {
    //         if (vis[t]) continue;
    //         vis[t] = true;
    //         ans.push_back(v);
    //         self(self, v);
    //     }
    // };
    // dfs(dfs, s);
    // if (ans.size() == m + 1) {
    //     for (auto i: ans) {
    //         std::cout << i + 1 << ' ';
    //     }
    // } else {
    //     std::cout << "No\n";
    // }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) nhir();
    return 0;
}
