//  P3916 图的遍历
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector g(n, std::vector<i32>());
    for (i32 i = 0; i < m; i++) {
        i32 u, v;
        std::cin >> u >> v;
        u--;
        v--;
        g[v].push_back(u);
    }
    std::vector<i32> ans(n);
    auto dfs = [&](auto &&self, i32 u, i32 f)-> void {
        ans[u] = f;
        for (auto i: g[u]) {
            if (ans[i]) continue;
            self(self, i, f);
        }
    };

    for (i32 i = n - 1; ~i; i--) {
        if (ans[i]) continue;
        dfs(dfs, i, i);
    }
    for (auto i: ans) {
        std::cout << i + 1 << ' ';
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
