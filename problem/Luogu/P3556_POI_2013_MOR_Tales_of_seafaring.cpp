//P3556 [POI 2013] MOR - Tales of seafaring
//  21:22
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int16_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};

void nhir() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector g(n, std::vector<i32>());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector que(n, std::vector<std::array<int, 3> >());
    for (int i = 0; i < k; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        s--, t--;
        que[s].push_back({t, d, i});
    }
    auto dfs = [&](i32 s = 0) {
        std::queue<int> q;
        std::vector<int> even(n, -1);
        std::vector<int> odd(n, -1);
        even[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (even[u] != -1) {
                for (auto v: g[u]) {
                    if (odd[v] == -1) {
                        odd[v] = even[u] + 1;
                        q.push(v);
                    }
                }
            }
            if (odd[u] != -1) {
                for (auto v: g[u]) {
                    if (even[v] == -1) {
                        even[v] = odd[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
        return std::pair{even, odd};
    };
    std::vector<bool> ans(k);
    for (int i = 0; i < n; i++) {
        if (que[i].size()) {
            auto an = dfs(i);
            for (auto [t,d,id]: que[i]) {
                if (t == i && g[t].size() == 0) {
                    ans[id] = !d;
                    continue;
                }
                if (d & 1) {
                    if (an.second[t] != -1 && an.second[t] <= d) {
                        // std::cout << "TAK\n";
                        ans[id] = 1;
                    } else {
                        // std::cout << "NIE\n";
                    }
                } else {
                    if (an.first[t] != -1 && an.first[t] <= d) {
                        // std::cout << "TAK\n";
                        ans[id] = 1;
                    } else {
                        // std::cout << "NIE\n";
                    }
                }
            }
        }
    }
    for (auto b: ans) {
        if (b) {
            std::cout << "TAK\n";
        } else {
            std::cout << "NIE\n";
        }
    }
    // auto dijkstra = [&](i32 s = 0)-> auto {
    //     using pii = std::pair<i32, i32>;
    //     std::vector<i32> dij_dis_odd(n, 0b01111111111111111);
    //     std::vector<i32> dij_dis_even(n, 0b01111111111111111);
    //     std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
    //     q.emplace(0, s);
    //     dij_dis_odd[s] = 0;
    //     // dij_dis_even[s] = 0;
    //     std::vector<bool> dij_vis(n);
    //     while (!q.empty()) {
    //         i32 u = q.top().second;
    //         q.pop();
    //         if (dij_vis[u]) continue;
    //         dij_vis[u] = true;
    //         for (auto v: g[u]) {
    //             if (dij_dis_odd[v] > dij_dis_even[u] + 1) {
    //                 dij_dis_odd[v] = dij_dis_even[u] + 1;
    //                 q.emplace(dij_dis_odd[v], v);
    //             }
    //
    //             if (dij_dis_even[v] > dij_dis_odd[u] + 1) {
    //                 dij_dis_even[v] = dij_dis_odd[u] + 1;
    //                 q.emplace(dij_dis_even[v], v);
    //             }
    //         }
    //     }
    //     return std::pair{dij_dis_odd, dij_dis_even};
    // };
    // std::vector<std::pair<std::vector<i32>, std::vector<i32> > > ans(n);
    // for (int i = 0; i < n; i++) {
    //     ans[i] = dijkstra(i);
    // }
    // while (k--) {
    //     int s, t, d;
    //     std::cin >> s >> t >> d;
    //     s--, t--;
    //     if (s == t && g[s].size() == 0) {
    //         std::cout << "NIE\n";
    //         continue;
    //     }
    //     if (d & 1) {
    //         if (ans[s].second[t] <= d && ans[s].second[t] != (int16_t) 0b01111111111111111) {
    //             std::cout << "TAK\n";
    //         } else {
    //             std::cout << "NIE\n";
    //         }
    //     } else {
    //         if (ans[s].first[t] <= d && ans[s].first[t] != (int16_t) 0b01111111111111111) {
    //             std::cout << "TAK\n";
    //         } else {
    //             std::cout << "NIE\n";
    //         }
    //     }
    // }
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
