//模板
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 998244853;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector<i64> dp1(n + 1), dp2(n + 1);
    std::vector<i32> ai(n + 1), pi(n + 1);
    for (i32 i = 1; i <= n; i++) {
        std::cin >> ai[i];
        ai[i] %= m;
    }
    for (i32 i = 1; i <= n; i++)std::cin >> pi[i];
    dp1[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            if (dp1[k] == 0) continue;
            dp2[k] = (dp2[k] + dp1[k] * (1 - pi[i] + mod) % mod) % mod;

            i64 t = (k + ai[i]) % m;
            dp2[t] = (dp2[t] + dp1[k] * pi[i] % mod) % mod;
        }
        dp1 = dp2;
        dp2 = std::vector<i64>(n + 1);
    }
    std::cout << dp1[1] << endl;
}

signed main() {
    IOS;
    i32 T = 1;

    while (T--) nhir();
    return 0;
}
