//  Another Day of Sun
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 998244353;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector dp(n + 1, std::array<i32, 2>());
    std::vector dp2(n + 1, std::array<i32, 2>());
    dp[0][0] = 1;
    for (i32 i = 0; i < n; i++) {
        if (v[i] == 1) {
            dp[i + 1][1] = (dp[i][1] + dp[i][0]) % mod;
            dp2[i + 1][1] = (dp2[i][1] + dp2[i][0] + dp[i][0]) % mod;
        } else if (v[i] == 0) {
            dp[i + 1][0] = (dp[i][0] + dp[i][1]) % mod;
            dp2[i + 1][0] = (dp2[i][1] + dp2[i][0]) % mod;
        } else {
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
            dp[i + 1][0] = (dp[i][0] + dp[i][1]) % mod;

            dp2[i + 1][0] = (dp2[i][1] + dp2[i][0]) % mod;
            dp2[i + 1][1] = (dp2[i][1] + dp2[i][0] + dp[i][0]) % mod;
        }
    }
    std::cout << (dp2[n][0] + dp2[n][1]) % mod << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}