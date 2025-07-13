//  D. Reachability and Tree
#include <bits/stdc++.h>

#define gcd std::gcd
using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector g(n, std::vector<i32>());
    for (i32 i = 1; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<i32> from(n, -1);
    std::vector<std::array<i32, 2>> ans;
    auto dfs = [&](this auto &&self, i32 u, i32 f) -> void {
        for (i32 v: g[u]) {
            if (v == f) continue;
            if (from[v] != -1) continue;
            if (from[u] == 1) {
                from[v] = 2;
                ans.push_back({u, v});
                self(v, u);
            } else {
                from[v] = 1;
                ans.push_back({{v, u}});
                self(v, u);
            }
        }
    };
    from[0] = 1;
    dfs(0, 0);
    i32 t = 0;
    for (i32 i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            if (g[g[i][0]].size() >= 2) {
                std::cout << "YES\n";
                for (auto &[x, y]: ans) {
                    if (x == i && t == 0) {
                        t++;
                        std::swap(x, y);
                    }
                    std::cout << x + 1 << ' ' << y + 1 << endl;
                }
                return;
            }
        }
    }
    std::cout << "NO\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}