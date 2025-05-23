auto dijkstra = [&](i32 s = 0) {
    using pii = std::pair<i32, i32>;
    std::vector<i32> dij_dis(n, 0x3f3f3f3f);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;
    q.emplace(0, s);
    dij_dis[s] = 0;
    std::vector<i32> dij_vis(n);
    while (!q.empty()) {
        i32 u = q.top().second;
        q.pop();
        if (dij_vis[u]) continue;
        dij_vis[u] = 1;
        for (auto [v, w]: g[u]) {
            if (dij_dis[v] > dij_dis[u] + w) {
                dij_dis[v] = dij_dis[u] + w;
                q.emplace(dij_dis[v], v);
            }
        }
    }
    return dij_dis;
};