//  C. Kevin and Puzzle
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 998244353;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i64> dp(n + 1), arr(n + 1);
    for (i32 i = 1; i <= n; i++) std::cin >> arr[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == arr[i - 1]) dp[i] += dp[i - 1] % mod;
        if (i > 1 && arr[i] == arr[i - 2] + 1) dp[i] += dp[i - 2] % mod;
    }
    std::cout << (dp[n] + dp[n - 1]) % mod << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
