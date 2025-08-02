//  E - A Path in A Dictionary
//  下午11:34
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    int64 n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector<std::array<int, 2>> adj(m);
    std::vector<int> dp(n, 0x3f3f3f3f);
    for (auto &[u, v]: adj) {
        std::cin >> u >> v;
        u--, v--;
        dp[u] = std::min(dp[u], v);
        dp[v] = std::min(dp[v], u);
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    if (OJ_NAME != "AtCoder")
    std::cin >> T;
    while (T--) nhir();
    return 0;
}