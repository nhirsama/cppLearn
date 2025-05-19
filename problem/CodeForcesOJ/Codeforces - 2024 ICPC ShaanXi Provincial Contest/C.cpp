#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;

    std::vector g(n + 1, std::vector<int>());
    for (int i = 0; i < n; i++) {
        int x = 1;
        std::cin >> x;
        g[i + 1].push_back(x);
    }
    int ans = 0;
    std::vector<int> ma(2 * n + 1);
    for (int i = 1; i <= n; i++) ma[i] = i;
    for (int i = 1; i <= n; i++) {
        std::vector<int> vis(2 * n + 1);
        auto dfs = [&](auto &&self, int x)-> bool {
            for (auto y: g[x]) {
                if (vis[y]) continue;
                vis[y] = true;
                if (!ma[y] || self(self, ma[y])) {
                    ma[y] = x;
                    return true;
                }
            }
            return false;
        };
        if (dfs(dfs, i)) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
}
