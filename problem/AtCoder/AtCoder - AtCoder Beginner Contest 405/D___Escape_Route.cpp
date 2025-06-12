//  D - Escape Route
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using pii = std::pair<i32, i32>;
i32 dx[] = {0, 0, 1, -1};
i32 dy[] = {1, -1, 0, 0};
char dc[] = {'<', '>', '^', 'v'};

void nhir() {
    i32 h, w;
    std::cin >> h >> w;
    std::vector g(h, std::string());
    for (auto &i: g) std::cin >> i;
    std::queue<pii> q;
    for (i32 i = 0; i < h; i++) {
        for (i32 j = 0; j < w; j++) {
            if (g[i][j] == 'E') {
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for (i32 k = 0; k < 4; k++) {
            i32 ix = x + dx[k], iy = y + dy[k];
            if (ix < 0 || ix >= h || iy < 0 || iy >= w) continue;
            if (g[ix][iy] == '.') {
                g[ix][iy] = dc[k];
                q.push({ix, iy});
            }
        }
    }
    for (auto &i: g) {
        std::cout << i << endl;
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
