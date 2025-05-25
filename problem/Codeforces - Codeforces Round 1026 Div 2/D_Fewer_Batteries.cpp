//  D. Fewer Batteries
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
using pii = std::pair<i32, i32>;
constexpr i32 inf = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector<i32> b(n);
    std::vector g(n, std::vector<pii>());
//    std::vector invg(n, std::vector<pii>());
    for (auto &x: b) std::cin >> x;
    for (i32 i = 0; i < m; i++) {
        i32 u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
    }
//    auto dijkstra = [&](i32 s = 0) {
//        std::vector<i32> dij_dis(n, -1);
//        std::priority_queue<pii> q;
//        q.push({0, s});
//        dij_dis[s] = {b[s]};
//        std::vector<bool> dij_vis(n);
//        while (!q.empty()) {
//            i32 u = q.top().second;
//            q.pop();
//            if (dij_vis[u]) continue;
//            dij_vis[u] = true;
//            for (auto [v, w]: g[u]) {
//                if (dij_dis[u] >= w && dij_dis[v] < dij_dis[u] + b[v]) {
////                    dij_dis[v] = dij_dis[u] + w;
//                    dij_dis[v] = dij_dis[u] + b[v];
//                    q.emplace(dij_dis[v], v);
//                }
//            }
//        }
//        return dij_dis;
//    };
//    auto dist = dijkstra();
//
//    if (dist[n - 1] == -1) {
//        std::cout << -1 << endl;
//        return;
//    }
    i32 l = 0, r = inf;
    auto check = [&](i32 mid) {
        std::vector<i32> dp(n);
        for (i32 i = 0; i < n; i++) {
            if (i && dp[i] == 0) continue;
            dp[i] = std::min(mid, dp[i] + b[i]);
            for (auto [x, y]: g[i]) {
                if (dp[i] >= y) {
                    dp[x] = std::max(dp[x], dp[i]);
                }
            }
        }
        return dp[n - 1];
//        std::queue<pii> q;
//        q.push({n - 1, mid});
//        while (!q.empty()) {
//            auto [u, w] = q.front();
//            q.pop();
//            w = std::min(dist[u], w);
//            for (auto &[v, ww]: invg[u]) {
//                if (w < ww) continue;
//                q.push({v, w});
//                if (v == 0) return true;
//            }
//        }
//        return false;
    };
    while (l < r) {
        i32 mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    std::cout << (r == inf ? -1 : r) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}