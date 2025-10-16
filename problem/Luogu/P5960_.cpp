//  P5960 【模板】差分约束
//  22:04
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};

void nhir() {
    int64 n, m;
    std::cin >> n >> m;
    std::vector g(n + 1, std::vector<std::array<int64, 2> >());
    std::vector<int> id(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        g[0].push_back({i, 0});
    }
    std::vector<int64> dist(n + 1, inf_i64);
    std::queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v,w]: g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(v);
                id[v]++;
                if (id[v] >= n) {
                    std::cout << "NO\n";
                    return;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << dist[i] << ' ';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        // std::cin >> T;
        while (T--) nhir();
    return 0;
}
