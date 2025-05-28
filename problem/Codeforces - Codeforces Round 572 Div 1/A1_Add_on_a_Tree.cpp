//  A1. Add on a Tree
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> din(n);
    std::vector g(n, std::vector<i32>());
    for (i32 i = 1; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
        din[u]++, din[v]++;
    }
    for (auto i: din) {
        if (i == 2) {
            std::cout << "NO\n";
            return;
        }
    }
//    for (i32 u = 0; u < n; u++) {
//        for (auto v: g[u]) {
//            if (din[u] != 1 && din[v] != 1) {
//                std::cout << "NO\n";
//                return;
//            }
//            if (din[u] != 1) {
//                bool ok = false;
//                for (auto t: g[u])
//                    if (din[t] == 1) {
//                        ok = true;
//                        break;
//                    }
//                if (!ok) {
//                    std::cout << "NO\n";
//                    return;
//                }
//            }
//            if (din[v] != 1) {
//                bool ok = false;
//                for (auto t: g[v])
//                    if (din[t] == 1) {
//                        ok = true;
//                        break;
//                    }
//                if (!ok) {
//                    std::cout << "NO\n";
//                    return;
//                }
//            }
//        }
//        bool ok = false;
//        if (i.size() == 1) continue;
//        for (auto u: i) {
//            if (din[u] == 1)ok = true;
//        }
//        if (!ok) {
//            std::cout << "NO\n";
//            return;
//        }
//    }
    std::cout << "YES\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}