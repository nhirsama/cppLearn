//  P1802 5 倍经验日
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, x;
    std::cin >> n >> x;
    std::vector<std::array<i32, 3> > w(n);
    i32 sum = 0;
    for (auto &[x,y,z]: w) std::cin >> x >> y >> z, y -= x, sum += x;
    std::vector<i32> dp(x + 1);
    for (i32 i = 1; i <= n; i++) {
        for (i32 j = x; j >= w[i - 1][2]; j--) {
            dp[j] = std::max(dp[j - w[i - 1][2]] + w[i - 1][1], dp[j]);
        }
    }
    std::cout << (dp[x] + sum) * 5 << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
