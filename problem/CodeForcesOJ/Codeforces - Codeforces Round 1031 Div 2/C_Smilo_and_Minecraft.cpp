//  C. Smilo and Minecraft
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> v(n);
    for (auto &i: v)std::cin >> i;
    i32 ans = 0;
    std::vector pre(n + 1, std::vector<i32>(m + 1));
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < m; j++) {
            if (v[i][j] == 'g') ans++, pre[i + 1][j + 1]++;
            pre[i + 1][j + 1] += pre[i + 1][j];
        }
    }
    for (i32 j = 0; j < m; j++) {
        for (i32 i = 0; i < n; i++) {
            pre[i + 1][j + 1] += pre[i][j + 1];
        }
    }
    i32 min = inf_i64;
    k--;
    for (i32 i = 1; i <= n; i++) {
        for (i32 j = 1; j <= m; j++) {
            if (v[i - 1][j - 1] == '.') {
                i32 x1 = std::max(1ll, i - k);
                i32 y1 = std::max(1ll, j - k);

                i32 x2 = std::max(1ll, i - k);
                i32 y2 = std::min(m, j + k);

                i32 x3 = std::min(n, i + k);
                i32 y3 = std::min(m, j + k);

                i32 x4 = std::min(n, i + k);
                i32 y4 = std::max(1ll, j - k);
                min = std::min(min, pre[x3][y3] - pre[x2 - 1][y2] - pre[x4][y4 - 1] + pre[x1 - 1][y1 - 1]);
            }
        }
    }
    std::cout << ans - min << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}