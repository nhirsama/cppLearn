//  I. FST: First Search Traversal
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> dfs(n), bfs(n);
    for (auto &i: dfs) std::cin >> i;
    for (auto &i: bfs) std::cin >> i;
    std::cout << (dfs[0] == bfs[0] ? "YES\n" : "NO\n");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
