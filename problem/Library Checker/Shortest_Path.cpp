//  Shortest Path  最短路径
//  上午2:16
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Library Checker"};

void nhir() {
    int n, m;
    std::cin >> n >> m;
    int s, t;
    std::cin >> s >> t;
    std::vector g(n, std::)
    auto dijkstra = [&](i32 s = 0) {
        using pii = std::pair<i32, i32>;
        std::vector<i32> dij_dis(n, 0x3f3f3f3f);
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;
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

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
//        std::cin >> T;
        while (T--) nhir();
    return 0;
}