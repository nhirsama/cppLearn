//模板
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr i32 mod = 998244353;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

void nhir() {
    i32 n, m, d;
    std::cin >> n >> m >> d;
    std::vector<std::string> g(n);
    for (auto &_: g)std::cin >> _;
    std::vector dp(n, std::vector(m, std::vector<i64>(2)));
    std::vector<i64> pref(m + 1), preg(m + 1);
    for (i32 i = 0; i < m; i++) {
        if (g[n - 1][i] == 'X')dp[n - 1][i][0] = 1;
    }
    for (i32 i = n - 1; ~i; i--) {
        for (i32 j = 0; j < m; j++) {
            if (g[i][j] == 'X') {
                if (i < n - 1) {
                    i32 l = std::max(j - d + 1, 0);
                    i32 r = std::min(j + d, m);
                    dp[i][j][0] = (pref[r] - pref[l] + preg[r] - preg[l] + mod + mod) % mod;
                }
            }
        }
        for (i32 j = 0; j < m; j++) {
            pref[j + 1] = (pref[j] + dp[i][j][0]) % mod;
        }
        for (i32 j = 0; j < m; j++) {
            if (g[i][j] == 'X') {
                i32 l = std::max(j - d, 0);
                i32 r = std::min(j + d + 1, m);
                dp[i][j][1] = (pref[r] - pref[l] - dp[i][j][0] + mod + mod) % mod;
            }
        }
        for (i32 j = 0; j < m; j++) {
            preg[j + 1] = (preg[j] + dp[i][j][1]) % mod;
        }
    }
    i64 ans = 0;
    ans = (pref[m] + preg[m]) % mod;
    std::cout << ans << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
