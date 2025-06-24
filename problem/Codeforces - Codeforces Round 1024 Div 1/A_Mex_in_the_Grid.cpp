//  A. Mex in the Grid
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
i32 dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
i32 dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector g(n, std::vector<i32>(n, -1));
    i32 tot = 0;
    std::deque<std::array<i32, 2>> q;
    q.push_front({n / 2, n / 2});
    g[n / 2][n / 2] = tot++;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        for (i32 i = 0; i < 8; i++) {
            i32 ix = x + dx[i];
            i32 iy = y + dy[i];
            if (ix >= n || ix < 0 || iy >= n || iy < 0) continue;
            if (g[ix][iy] != -1)continue;
            g[ix][iy] = tot++;
            q.push_front({ix, iy});
        }
    }
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < n; j++) {
            std::cout << g[i][j] << ' ';
        }
        std::cout << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}