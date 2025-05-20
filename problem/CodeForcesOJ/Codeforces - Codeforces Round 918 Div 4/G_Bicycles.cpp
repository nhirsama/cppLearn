//  G. Bicycles
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using pii = std::pair<i32, i32>;

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector g(n, std::vector<pii>());
    for (i32 i = 0; i < m; i++) {
        i32 u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    std::vector<i32> b(n);
    for (auto &i: b) std::cin >> i;
    std::vector dist(n, std::vector<i32>(n, 0x3f3f3f3f3f));
    dist[0][0] = 0;
    std::priority_queue<std::array<i32, 3>, std::vector<std::array<i32, 3> >, std::greater<> > pq;
    pq.push({0, 0, 0});
    //std::vector st(n, std::vector<bool>(n));
    while (!pq.empty()) {
        auto [_,u,bi] = pq.top();
        pq.pop();
        for (auto [v,w]: g[u]) {
            i32 nw = _ + w * b[bi];
            i32 nb = (b[v] < b[bi] ? v : bi);
            if (dist[v][nb] > nw) {
                dist[v][nb] = nw;
                pq.push({nw, v, nb});
            }
        }
    }
    i32 ans = 0x3f3f3f3f3f3f;
    for (i32 i = 0; i < n; i++) ans = std::min(ans, dist[n - 1][i]);
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
