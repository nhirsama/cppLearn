//  B. Sagheer, the Hausmeister
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector<std::string> v(n);
    for (i32 i = n - 1; ~i; i--) std::cin >> v[i];
    std::vector<std::array<i32, 2> > dp(n + 1);
    dp[0][1] = 0x3f3f3f3f3f;
    i32 ans = 0x3f3f3f3f3f3f;
    for (i32 i = 1; i <= n; i++) {
        i32 l = m + 1, r = 0;
        for (i32 j = 1; j <= m; j++) {
            if (v[i - 1][j] == '1') {
                if (l == m + 1) l = j;
                r = j;
            }
        }
        if (l != m + 1 || r != 0) ans = 0x3f3f3f3f3f;
        //std::cout<<l<<' ' <<r<<endl;
        dp[i][0] += dp[i - 1][0] + (r * 2) + 1;
        dp[i][1] += dp[i - 1][1] + (m + 1 - l) * 2 + 1;
        dp[i][0] = std::min(dp[i][0], dp[i - 1][1] + m + 2);
        dp[i][1] = std::min(dp[i][1], dp[i - 1][0] + m + 2);
        ans = std::min(dp[i - 1][0] + r, ans);
        ans = std::min(dp[i - 1][1] + (m + 1 - l), ans);
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
