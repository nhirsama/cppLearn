#include <bits/stdc++.h>
#define int long long
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector v(n + 1, std::vector<int>(m + 1));
    auto add = [&](int n, int m, int i) {
        int t = std::max(0ll, std::min(n, m) - 1);
        int sum = 0;
        if (n >= m) {
            for (int k = 1; k <= t; k++) {
                sum += std::min(std::min(std::min(i, m - i), k), t - k + 1);
            }
        } else {
            for (int k = 1; k <= t; k++) {
                sum += std::min(std::min(i, m - i), k);
            }
        }
        return sum;
    };
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            v[i][j] += std::min(i, j) + std::min(n - i, j) + std::min(i, m - j) + std::min(n - i, m - j);
            v[i][j] += add(i, m, j);
            v[i][j] += add(n - i, m, j);
            v[i][j] += add(j, n, i);
            v[i][j] += add(m - j, n, n-i);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            std::cout << v[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) {
        solve();
    }
}
