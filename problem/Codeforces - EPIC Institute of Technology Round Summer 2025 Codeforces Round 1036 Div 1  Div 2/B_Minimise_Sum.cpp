//  B. Minimise Sum
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    int n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    std::cout << v[0] + std::min(v[0], v[1]) << endl;
//    std::vector<i32> dp(n + 1, inf_i64);
//    i32 sum = 0;
//    for (i32 i = 0; i < n; i++) {
//        dp[i + 1] = std::min(dp[i], v[i]);
////        sum += dp[i + 1];
//    }
//    for (i32 i = n-1;i;i--){
//        dp[i]+=dp[i+1];
//    }
//    i32 min = inf_i64;
//    for (i32 i = 0;i<n;i++){
//
//    }
//    if (n > 2) sum -= *std::min_element(dp.begin() + 1, dp.end());
//    std::cout << sum << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}