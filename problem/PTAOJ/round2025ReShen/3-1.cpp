//
// Created by zxy15 on 25-4-18.
//
//
// Created by zxy15 on 25-4-16.
//
#include <bits/stdc++.h>
using pii = std::pair<int, int>;

int main() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    s--, t--;
    std::vector g(n, std::vector<pii>());
    std::vector rd(n, 0);
    for (auto &i: rd) std::cin >> i;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        g[v].push_back(pii(u, w));
        g[u].push_back(pii(v, w));
    }
    std::vector<bool> st(n);
    std::priority_queue<pii> pq;
    std::vector<int> dist(n, 0x3f3f3f3f);
    st[s] = dist[s] = 0;
    pq.push(pii(0, s));
    rd[s] = rd[t] = 0;
    while (!pq.empty()) {
        auto [y,x] = pq.top();
        pq.pop();
        st[x] = true;
        for (auto [u,w]: g[x]) {
            if (dist[u] > dist[x] + w) {
                dist[u] = dist[x] + w;
                rd[u] = std::max(rd[u], rd[x]);
                if (!st[u]) pq.push(pii(dist[u], u));
            }
        }
    }
    std::cout << dist[t] << ' ' << rd[t] << std::endl;
}
