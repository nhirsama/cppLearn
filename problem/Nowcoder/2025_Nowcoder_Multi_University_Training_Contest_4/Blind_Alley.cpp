////  Blind Alley
//#include <bits/stdc++.h>
//
//using int64 = int64_t;
////using i32 = int64_t;
////constexpr int mod = 1e9 + 7;
////constexpr char endl = '\n';
////constexpr char enld = '\n';
////constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
////
////void nhir() {
////    int64 n, m, k;
////    std::cin >> n >> m >> k;
////    std::vector g(n, std::string());
////    for (auto &i: g) std::cin >> i;
////
////}
////
////
////signed main() {
////    std::ios::sync_with_stdio(false);
////    std::cin.tie(nullptr);
////    int T = 1;
////    std::cin >> T;
////    while (T--) nhir();
////    return 0;
////}


#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using int64 = int64_t;
//using i32 = int64_t;
//constexpr int mod = 1e9 + 7;
//constexpr char endl = '\n';
//constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
int dxy[4][2] = {{0,  1},
                 {0,  -1},
                 {1,  0},
                 {-1, 0}};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

//    vector g(n, vector<char>(m));
    std::vector<std::string> g(n);
    for (auto &i: g) std::cin >> i;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cin >> g[i][j];
//        }
//    }

    auto bfs = [&](int sx, int sy, int t, auto &vis) {
//        vector vis(n, vector<bool>(m));
        queue<pair<int, int> > q;
        q.push({sx, sy});
        vis[sx][sy] = 1;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
                if (i != t) {
                    int nx = x + dxy[i][0];
                    int ny = y + dxy[i][1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || g[nx][ny] == '1') continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
        }
        return vis;
    };
    vector vis1(n + 10, vector<bool>(m + 10));
    vector vis2(n + 10, vector<bool>(m + 10));
    bfs(0, 0, 1, vis1);
    bfs(0, m - 1, 0, vis2);

    std::vector qwq(n, std::vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            qwq[i][j] = (vis1[i][j] && !vis2[i][j]);
        }
    }
    std::vector dp(n, std::vector<int64>(m));

    for (int j = m - 1; ~j; j--) {
        for (int i = 0; i < n; i++) {
            if (qwq[i][j]) {
                if (j < m - 1) dp[i][j] = std::max(dp[i][j], dp[i][j + 1] + 1);
//                if (i < n - 1) dp[i][j] = std::max(dp[i][j], dp[i + 1][j]);
//                if (0 < i) dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
//                if (0 < i && qwq[i - 1][j]) { dp[i - 1][j] = std::max(dp[i - 1][j], dp[i][j]); }
            }
        }
        for (int i = 0; i < n; i++) if (qwq[i][j] && 0 < i) dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
        for (int i = n - 1; ~i; i--) if (qwq[i][j] && i < n - 1) dp[i][j] = std::max(dp[i][j], dp[i + 1][j]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] >= k) {
                std::cout << "Yes\n";
                return;
            }
        }
    }
    std::cout << "No\n";
//    auto bfs1 = [&](int sx, int sy) {
////        bool lift = false;
////        for (int i = sx; i < n; i++) {
////            if (qwq[i][sy] && vis1[i][sy]) lift = true;
////        }
//        vector vis(n, vector<bool>(m));
//        queue<pair<int, int> > q;
//        q.push({sx, sy});
//        vis[sx][sy] = true;
//        i64 miny = sy, maxy = sy;
//        qwq[sx][sy] = false;
//        while (q.size()) {
//            auto [x, y] = q.front();
////            qwq[x][y] = false;
//            q.pop();
//            for (int i = 0; i < 4; i++) {
//                int64 nx = x + dxy[i][0];
//                int64 ny = y + dxy[i][1];
//                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//                if (!qwq[nx][ny]) continue;
//                vis[nx][ny] = true;
//                qwq[nx][ny] = false;
//                q.push({nx, ny});
//                miny = min(miny, ny);
//                maxy = max(maxy, ny);
////                miny = min(min)
//            }
//        }
//        return maxy - miny + 1;
//    };
//    int64 ans = 0;
////    for (int i = 0; i < n; i++) {
////        for (int j = 0; j < m; j++) {
////            std::cout << (int) qwq[i][j];
////        }
////        std::cout << endl;
////    }
////    for (int i = 0; i < n; i++) {
////        for (int j = 0; j < m; j++) {
////            if (qwq[i][j]) ans = max(ans, bfs1(i, j));
////        }
////    }
//    for (int j = 0; j < m; j++) {
//        for (int i = 0; i < n; i++) {
//            if (qwq[i][j]) ans = max(ans, bfs1(i, j));
//        }
//    }
////    std::cout<<ans<<endl;
//    std::cout << (ans >= k ? "Yes" : "No") << '\n';
////    bfs1(0, 0);
//
////    bool f = false;
////    std::vector<bool> to1(m + 1);
////    for (int i = 1; i <= n; i++) {
////        for (int q = 1; q <= m; q++) {
////            if (vis1[i][q] && !vis2[i][q]) {
////                to1[q] = true;
////            }
////        }
////        int cnt = 0;
////        for (int j = 2; j < m; ++j) {
////            if (to1[j]) {
////                if (++cnt >= k) f = true;
////            } else cnt = 0;
////        }
////    }
////    if (f) {
////        cout << "Yes\n";
////    } else {
////        cout << "No\n";
////    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}