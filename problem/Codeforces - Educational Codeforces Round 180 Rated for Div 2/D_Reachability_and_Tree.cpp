//  D. Reachability and Tree
#include <bits/stdc++.h>

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
    i32 t = 0;
    for (; t <= n; t++) {
        if (t == n) {
            std::cout << "NO\n";
            return;
        }
        if (g[t].size() == 2)break;
    }
    std::vector<i32> from(n, -1);
    std::vector<std::array<i32, 2>> ans;
    from[t] = 1;
    from[g[t][0]] = 1;
    from[g[t][1]] = 2;
    ans.push_back({g[t][0], t});
    ans.push_back({t, g[t][1]});
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
    dfs(g[t][0], g[t][0]);
    dfs(g[t][1], g[t][1]);
    std::cout << "YES\n";
    for (auto [x, y]: ans) {
        std::cout << x + 1 << ' ' << y + 1 << endl;
    }
//    for (i32 i = 0; i < n; i++) {
//        if (g[i].size() == 1) {
//            from[i] = 1;
//            dfs(i, i);
//            break;
//        }
//    }
//    auto bfs = [&]() {
//        std::queue<i32> q;
//        q.push(0);
//        while (!q.empty()) {
//            auto u = q.front();
//            q.pop();
//            for (i32 v: g[u]) {
//                if (from[v] != -1) continue;
//                if (from[u] == 1) {
//                    from[v] = 2;
//                    ans.push_back({u, v});
//                    q.push(v);
//                } else {
//                    from[v] = 1;
//                    ans.push_back({{v, u}});
//                    q.push(v);
//                }
//            }
//        }
//    };
//    bfs();
//    i32 fl = 0;
//    for (i32 i = 0; i < n; i++) {
//        if (g[i].size() == 2 && from[i] == 2 && (g[g[i][0]].size() == 1 || g[g[i][1]].size() == 1)) {
//            std::cout << "YES\n";
//            for (auto &[x, y]: ans) {
//                if (y == i && g[i][1] == x && fl == 0 && g[g[i][1]].size() == 1) {
//                    std::swap(x, y);
//                    fl++;
//                }
//                if (y == i && g[i][0] == x && fl == 0 && g[g[i][0]].size() == 1) {
//                    std::swap(x, y);
//                    fl++;
//                }
//                std::cout << x + 1 << ' ' << y + 1 << endl;
//            }
//            return;
//        }
//    }
//
//    for (i32 i = 0; i < n; i++) {
//        if (g[i].size() == 2 && from[i] == 1 && (g[g[i][0]].size() == 1 || g[g[i][1]].size() == 1)) {
//            std::cout << "YES\n";
//            for (auto &[y, x]: ans) {
//                if (y == i && g[i][1] == x && fl == 0 && g[g[i][1]].size() == 1) {
//                    std::swap(x, y);
//                    fl++;
//                }
//                if (y == i && g[i][0] == x && fl == 0 && g[g[i][0]].size() == 1) {
//                    std::swap(x, y);
//                    fl++;
//                }
//                std::cout << x + 1 << ' ' << y + 1 << endl;
//            }
//            return;
//        }
//    }
//        if (g[i].size() == 1 && from[i] == 1) {
//            if (g[g[i][0]].size() == 2) {
//                std::cout << "YES\n";
//                for (auto &[x, y]: ans) {
//                    if (x == i && t == 0) {
//                        t++;
//                        std::swap(x, y);
//                        //std::cout << "swap" << x + 1 << y + 1 << endl;
//                    }
//                    std::cout << x + 1 << ' ' << y + 1 << endl;
//                }
//                return;
//            }
//        }

//    t = 0;
//    for (i32 i = 0; i < n; i++) {
//        if (g[i].size() == 1 && from[i] == 2) {
//            if (g[g[i][0]].size() == 2) {
//                std::cout << "YES\n";
//                for (auto &[y, x]: ans) {
//                    if (x == i && t == 0) {
//                        t++;
//                        std::swap(x, y);
//                        //std::cout << "swap" << x + 1 << y + 1 << endl;
//                    }
//                    std::cout << x + 1 << ' ' << y + 1 << endl;
//                }
//                return;
//            }
//        }
//    }
//    std::cout << "NO\n";
//    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}