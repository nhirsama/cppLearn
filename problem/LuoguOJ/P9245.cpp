//P9245 [蓝桥杯 2023 省 B] 景区导游
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::vector g(n, std::vector<pii>());
    for (i32 i = 1; i < n; i++) {
        i32 u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    std::vector<i32> to(k);
    for (auto &i: to) std::cin >> i, i--;
    std::vector<i64> dist(n);
    auto dfs = [&](auto &&self, i32 u, i32 f)-> void {
        for (auto v: g[u]) {
            if (v.first == f) continue;
            dist[v.first] = dist[u] + v.second;
            self(self, v.first, u);
        }
    };
    dfs(dfs, 0, -1);
    i64 ans = 0;
    for (auto i: to) {
        ans += dist[i];
    }
    for (auto i: to) {
        std::cout << ans - dist[i] << " ";
    }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }

    while (T--) nhir();
    return 0;
}
