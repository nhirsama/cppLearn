//  D - Domino Covering XOR
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 h, w;
    std::cin >> h >> w;
    std::vector<i32> v(h * w);
    for (auto &i: v) std::cin >> i;
    std::vector<bool> vis(h * w + w);
    i32 ans = 0;
    auto dfs = [&](auto &&self, i32 u, i32 Xor) -> void {
        if (u >= h * w) {
            ans = std::max(ans, Xor);
            return;
        }
        if (vis[u]) {
            self(self, u + 1, Xor);
            return;
        }
        vis[u] = true;
        self(self, u + 1, Xor ^ v[u]);
        vis[u] = false;
        if ((u % w != w - 1) && !vis[u + 1]) {
            vis[u] = vis[u + 1] = true;
            self(self, u + 1, Xor);
            vis[u] = vis[u + 1] = false;
        }
        if ((u / w != h - 1) && !vis[u + w]) {
            vis[u] = vis[u + w] = true;
            self(self, u + 1, Xor);
            vis[u] = vis[u + w] = false;
        }
    };
    dfs(dfs, 0, 0ll);
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}