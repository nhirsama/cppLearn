//P3143 [USACO16OPEN] Diamond Collector S
#include <bits/stdc++.h>
using i64 = long long int;
using i32 = int;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

void nhir() {
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (auto &_: a) std::cin >> _;
    std::sort(a.begin(), a.end());
    std::vector dp(n + 1, std::vector<i64>(2, 0));
    for (i64 i = 0; i < n; i++) {
        i64 j = i;
        while (j < n && a[j] - a[i] <= k)j++;
        dp[i][0] = j - i;
        dp[j][1] = std::max(dp[j][1], j - i);
    }
    i64 ans = 0, max = 0;
    for (i32 i = 0; i <= n; i++) {
        max = std::max(max, dp[i][1]);
        ans = std::max(ans, max + dp[i][0]);
    }
    std::cout << ans << std::endl;
}

signed main() {
    IOS;
    nhir();
    return 0;
}
