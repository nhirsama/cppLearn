//  H. Mad City
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, a, b;
    std::cin >> n >> a >> b;
    a--, b--;
    std::vector g(n, std::vector<i32>());
    for (i32 i = 0; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (a == b) {
        std::cout << "NO\n";
        return;
    }
    std::vector<i32> vis(n, -1);
    i32 sta = -1;
    vis[b] = 0;
    auto dfs1 = [&](auto &&self, i32 u, i32 f) -> bool {
        for (auto v: g[u]) {
            if (v == f) continue;
            if (vis[v] != -1) {
                sta = v;
                return true;
            }
            vis[v] = vis[u] + 1;
            if (self(self, v, u)) return true;
        }
        return false;
    };
    dfs1(dfs1, b, b);
    std::vector<i32> dis(n, 1E18);
    auto dijkstra = [&](i32 s) -> void {
        using PII = std::pair<i32, i32>;
        std::priority_queue<PII, std::vector<PII>, std::greater<PII>> q;
        q.emplace(0, s);
        dis[s] = 0;
        std::vector<i32> viss(n + 1);
        while (!q.empty()) {
            i32 x = q.top().second;
            q.pop();
            if (viss[x]) continue;
            viss[x] = 1;
            for (auto y: g[x]) {
                if (dis[y] > dis[x] + 1) {
                    dis[y] = dis[x] + 1;
                    q.emplace(dis[y], y);
                }
            }
        }
    };
    dijkstra(a);
//    for (auto i: vis) {
//        std::cout << i << ' ';
//    }
//    std::cout << '\n';
//    std::cout << sta << ' ' << vis[sta] << ' ' << dis[sta] << '\n';
    std::cout << (dis[sta] <= vis[sta] ? "NO\n" : "YES\n");
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}