//P2280 [HNOI2003] 激光炸弹
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 5e3 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i64 n, m;
    std::cin >> n >> m;
    std::vector g(N, std::vector<i64>(N));
    for (i32 i = 1; i <= n; i++) {
        i32 x,y, v;
        std::cin >> x >> y >> v;
        g[x + 1][y + 1] += v;
    }
    for (i32 i = 1; i < N; i++) {
        for (i32 j = 1; j < N; j++) {
            g[i][j] += g[i][j - 1];
        }
    }
    for (i32 j = 1; j < N; j++) {
        for (i32 i = 1; i < N; i++) {
            g[i][j] += g[i - 1][j];
        }
    }
    i64 ans = 0;
    for (i32 i = m; i < N; i++) {
        for (i32 j = m; j < N; j++) {
            ans = std::max(ans, g[i][j] - g[i][j - m] - g[i - m][j] + g[i - m][j - m]);
        }
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }

    while (T--) nhir();
    return 0;
}
