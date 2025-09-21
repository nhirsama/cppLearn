#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int ans = 0;
    std::vector<int> ccb(n + 1);
    auto find = [&](auto &&self, int x) -> int {
        return ccb[x] == x ? x : ccb[x] = self(self, ccb[x]);
    };
    std::vector<int> v(n);
    for (int i = n - 1; ~i; i--) v[i] = n - i;
    for (int ju = 0; ju < n; ju++) {
        for (int i = 0; i <= n; i++) ccb[i] = i;
        for (int i = 0; i < n; i++) {
            ccb[find(find, i + 1)] = find(find, v[(i + ju) % n]);
        }
        std::vector<bool> vis(n + 1);
        for (int i = 1; i <= n; i++) {
            vis[find(find, i)] = true;
        }
        for (int i = 0; i < n; i++) {
            if (vis[v[i]])ans++;
        }
    }
    std::cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << v[i] << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) {
        solve();
    }
}
