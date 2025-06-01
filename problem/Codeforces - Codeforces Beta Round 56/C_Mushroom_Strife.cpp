//  C. Mushroom Strife
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
using arr3 = std::array<i32, 3>;

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector g(n, std::vector<arr3>());
    while (m--) {
        i32 u, v, lcm, gcd;
        std::cin >> u >> v >> gcd >> lcm;
//        if (std::gcd(gcd, lcm) != gcd) {
//            std::cout << "NO\n";
//            return;
//        }
        u--, v--;
        g[u].push_back({v, gcd, lcm});
        g[v].push_back({u, gcd, lcm});
    }
    std::vector<i32> ans(n);
    for (i32 i = 0; i < n; i++) {
        if (ans[i]) continue;
        if (g[i].size() == 0) {
            ans[i] = 1;
            continue;
        }
        i32 gcd = 0;
        for (auto &j: g[i]) gcd = std::gcd(gcd, j[2]);
        for (i32 j = 1; j <= gcd; j++) {
            if (gcd % j) continue;
            auto dfs = [&](this auto &&dfs, i32 u, i32 zz) -> bool {
                for (auto [v, gc, lc]: g[u]) {
                    if (ans[v]) continue;
                    if (zz > lc * gc) continue;
                    ans[v] = lc * gc / zz;
                    if (!dfs(v, ans[v])) {
                        ans[v] = 0;
                        return false;
                    }
                }
                for (auto [v, gc, lc]: g[u]) {
                    if (std::gcd(ans[u], ans[v]) != gc || std::lcm(ans[u], ans[v]) != lc) {
                        ans[v] = 0;
                        return false;
                    }
                }
                return true;
            };
            if (dfs(i, j)) break;
        }
    }
    if (std::ranges::find(ans, 0) == ans.end()) {
        std::cout << "YES\n";
        for (auto i: ans) {
            std::cout << i << ' ';
        }
    } else {
        std::cout << "NO\n";
//        for (auto i: ans) {
//            std::cout << i << ' ';
//        }
    }
//    std::vector<i32> ys;
//    i32 max = 0x3f3f3f3f3f;
//    for (auto v: g[0]) {
//        max = std::min(max, v[1]);
//    }
//    auto get = [&](i32 i) -> bool {
//        for (auto v: g[0]) {
//            if (v[1] % i) return false;
//        }
//        return true;
//    };
//    for (i32 i = 1; i * i <= max; i++) {
//        if (get(i)) {
//            ys.push_back(max / i);
//            if (max / i != i)ys.push_back(i);
//        }
//    }
//    auto bfs = [&](i32 yss) {
//        std::vector<i32> ans(n);
//        std::queue<std::array<i32, 3>> q;
//        q.push({0, -1, yss});
//        while (!q.empty()) {
//            auto &[u, f, y] = q.front();
//            q.pop();
//
//        }
//    };
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}