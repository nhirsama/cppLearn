//  D. D/D/D
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, m, l;
    std::cin >> n >> m >> l;
//    std::vector<i32> odd, even;
    i32 oddmin = inf_i64;
    i32 sum = 0;
    while (l--) {
        i32 a;
        std::cin >> a;
        sum += a;
        if (a & 1) oddmin = std::min(oddmin, a);
//        if (a & 1) even.push_back(a);
//        else odd.push_back(a);
    }
    std::vector g(n, std::vector<i32>());
    while (m--) {
        i32 u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dijkstra = [&](i32 s = 0) {
        std::vector<std::array<i32, 2>> dij_dis(n, {inf_i64, inf_i64});
        std::queue<std::array<i32, 2>> q;
        q.push({0, 0});
        dij_dis[0][0] = 0;
        while (q.size()) {
            auto [u, p] = q.front();
            q.pop();
            for (auto v: g[u]) {
                if (dij_dis[v][!p] > dij_dis[u][p] + 1) {
                    dij_dis[v][!p] = dij_dis[u][p] + 1;
                    q.push({v, !p});
                }
            }
        }
        return dij_dis;
    };
    auto dist = dijkstra(0);

//    i32 oddsum = 0, evensum = 0;
//    std::ranges::sort(odd);
//    std::ranges::sort(even);

//    oddsum = std::accumulate(odd.begin(), odd.end(), 0);
//    evensum = oddsum;
//    if (even.size()) {
//        evensum += std::accumulate(even.begin(), even.end(), 0);
//        if (even.size() % 2 == 0) {
//            evensum -= even[0];
//        }
//        oddsum += std::accumulate(even.begin(), even.end(), 0);
//        if (even.size() & 1) {
//            oddsum -= even[0];
//        }
//    }

    for (i32 i = 0; i < n; i++) {
        i32 ans = 0;
        for (i32 j = 0; j < 2; j++) {
            i32 d = sum - (j == sum % 2 ? 0 : oddmin);
            if (dist[i][j] <= d) ans = 1;
        }
        std::cout << ans;
    }
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}