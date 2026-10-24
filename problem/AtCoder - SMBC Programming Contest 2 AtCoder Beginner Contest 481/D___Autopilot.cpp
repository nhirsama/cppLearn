//  D - Autopilot
//  20:23
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    i32 n, m, s, t;
    std::cin >> n >> m >> s >> t;
    s--, t--;
    std::vector g(n, std::vector<std::pair<i32, i32> >());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back({v, 1});
    }
    for (int i = 0; i < n; i++) {
        if (g[i].empty()) continue;
        std::ranges::sort(g[i], [](auto a, auto b)-> bool {
            return a.first < b.first;
        });
        // for (auto j: g[i]) {
        //     std::cout << j.first << ' ' << j.second << endl;
        // }
        // g[i].push_back({g[i].begin()->first, 0});
        g[i][0].second = 0;
    }
    auto dijkstra = [&](i32 s = 0) {
        using pii = std::pair<i32, i32>;
        std::vector<i32> dij_dis(n, 0x3f3f3f3f);
        std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
        q.emplace(0, s);
        dij_dis[s] = 0;
        std::vector<bool> dij_vis(n);
        while (!q.empty()) {
            i32 u = q.top().second;
            q.pop();
            if (dij_vis[u]) continue;
            dij_vis[u] = true;
            for (auto [v, w]: g[u]) {
                if (dij_dis[v] > dij_dis[u] + w) {
                    dij_dis[v] = dij_dis[u] + w;
                    q.emplace(dij_dis[v], v);
                }
            }
        }
        return dij_dis;
    };
    auto dist = dijkstra(s);
    if (dist[t] >= 0x3f3f3f3f) {
        std::cout << -1 << endl;
        return;
    }
    std::cout << dist[t] << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}
