//  Fastest Coverage Problem
//  下午1:09
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

void nhir() {
    int64 n, m;
    std::cin >> n >> m;
    std::vector g(n, std::vector<int>(m, -1));
    std::queue<std::array<int, 2>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> g[i][j];
            g[i][j]--;
            if (g[i][j] == 0) q.push({i, j});
        }
    }
    int max = -1;
    [&]() {
        int dx[]{0, 0, 1, -1};
        int dy[]{1, -1, 0, 0};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            max = std::max(max, g[x][y]);
            for (int i = 0; i < 4; i++) {
                int ix = x + dx[i];
                int iy = y + dy[i];
                if (ix < 0 || iy < 0 || ix >= n || iy >= m) continue;
                if (g[ix][iy] != -1) continue;
                g[ix][iy] = g[x][y] + 1;
                q.push({ix, iy});
                max = std::max(max, g[ix][iy]);
            }
        }
    }();
//    if (max == -1) {
//        std::cout << (n + m + 1) / 2 << endl;
//        return;
//    }
    int64 l = 0, r = n + m;
    while (l < r) {
        int64 mid = (l + r) >> 1;
        if ([&]() -> bool {
            int64 L1 = -inf_i64, L2 = -inf_i64, R1 = inf_i64, R2 = inf_i64;
            for (int64 i = 0; i < n; i++) {
                for (int64 j = 0; j < m; j++) {
                    if (g[i][j] > mid || g[i][j] == -1) {
                        L1 = std::max(L1, (i + j) - mid);
                        L2 = std::max(L2, (i - j) - mid);
                        R1 = std::min(R1, (i + j) + mid);
                        R2 = std::min(R2, (i - j) + mid);
                    }
                }
            }
            if (L1 % 2 != L2 % 2) {
                if (L1 < R1) {
                    L1++;
                } else if (L2 < R2) {
                    L2++;
                } else {
                    return 0;
                }
            }
            return (L1 <= R1 && L2 <= R2);
//            int64 l1 = inf_i64, r1 = -inf_i64, l2 = inf_i64, r2 = -inf_i64;
//            for (int64 i = 0; i < n; i++) {
//                for (int64 j = 0; j < m; j++) {
//                    if (g[i][j] > mid || g[i][j] == -1) {
//                        int x = i + j, y = i - j;
//                        mina = std::min(mina, i + j - mid);
//                        maxa = std::max(maxa, i - j + mid);
//                        minb = std::min(minb, i + j + mid);
//                        maxb = std::max(maxb, i - j - mid);
//                    }
//                }
//            }
//            if (mina % 2 != minb % 2) {
//                if (mina < maxa)mina++;
//                else if (minb < maxb) minb++;
//                else return false;
//            }
//            return (mina <= maxa && mina <= maxb);
        }()) {
            r = mid;
        } else l = mid + 1;
    }
    std::cout << r << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
//        std::cin >> T;
        while (T--) nhir();
    return 0;
}