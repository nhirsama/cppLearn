//  F. Clique in the Divisibility Graph
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
constexpr __i_know_i_need_int N = 1e6 + 10;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    std::vector<i32> cnt(N), dp(N);
    for (auto &i: v) std::cin >> i, cnt[i]++;
    for (i32 i = 1; i <= 1e6; i++) {
        dp[i] += cnt[i];
        for (i32 j = i; j <= 1e6; j += i) {
            dp[j] = std::max(dp[j], dp[i]);
        }
    }
    // for (auto i: v) {
    //     for (i32 j = 1; j * j <= i; j++) {
    //         if (dp[i]) {
    //             if (i % j == 0) {
    //                 dp[i] = std::max(dp[i], dp[j] + 1);
    //                 if (i % j != j && dp[i / j] && j != 1)
    //                     dp[i] = std::max(dp[i], dp[i / j] + 1);
    //             }
    //         }
    //     }
    // }
    std::cout << *std::ranges::max_element(dp) << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
