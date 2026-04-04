//  P3018 [USACO11MAR] Tree Decoration G
//  09:02
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector v(n, std::vector<i32>());
    std::vector<i32> c(n), t(n);
    for (i32 i = 0; i < n; i++) {
        i32 P;
        std::cin >> P >> c[i] >> t[i];
        if (P != -1) {
            v[P - 1].push_back(i);
        }
    }
    std::vector<i32> dptot(n), dpmin(n, inf_i64);
    i32 ans = 0;
    auto dfs = [&](auto &&self, i32 f, i32 u)-> void {
        dpmin[u] = t[u];
        for (auto vv: v[u]) {
            self(self, u, vv);
            dpmin[u] = std::min(dpmin[u], dpmin[vv]);
            dptot[u] += dptot[vv];
        }
        ans += ((c[u] - dptot[u] >= 0) ? (c[u] - dptot[u]) * dpmin[u] : 0);
        dptot[u] += ((c[u] - dptot[u] >= 0) ? (c[u] - dptot[u]) : 0);
    };

    dfs(dfs, -1, 0);
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int v = 1;
    if (OJ_NAME != "AtCoder")
        // std::cin >> v;
        while (v--) nhir();
    return 0;
}
