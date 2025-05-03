#include <bits/stdc++.h>
using i32 = long long;
using pii = std::pair<i32, i32>;

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    i32 n, m;
    std::cin >> n >> m;
    std::vector g(2 * n + 1, std::vector<pii>());
    for (i32 i = 0; i < m; i++) {
        i32 u, v, w;
        std::cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        g[u + n].push_back({v + n, w});
        g[v + n].push_back({u + n, w});
        g[v].push_back({v + n, 0});
        g[u].push_back({u + n, 0});
        g[u].push_back({v + n, 0});
        g[v].push_back({u + n, 0});
    }
    for (i32 i = 1; i <= n; i++) {
        i32 w;
        std::cin >> w;
        g[0].push_back({i, w});
    }
    std::vector<i32> dist(2 * n + 1, 0x3f3f3f3f3f3f3f3f);
    dist[0] = 0;
    std::vector<bool> st(2 * n + 1);
    std::priority_queue<pii, std::vector<pii>, std::greater<> > pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [wpq,u] = pq.top();
        pq.pop();
        if (st[u]) continue;
        st[u] = true;
        for (auto [v,w]: g[u]) {
            if (dist[v] > dist[u] + w) {
                if (st[v]) continue;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    i32 ans = 0;
    for (i32 i = n + 1; i <= 2 * n; i++) {
        //std::cout << dist[i] << std::endl;
        ans = std::max(ans, dist[i]);
    }
    std::cout << ans << '\n';
}
