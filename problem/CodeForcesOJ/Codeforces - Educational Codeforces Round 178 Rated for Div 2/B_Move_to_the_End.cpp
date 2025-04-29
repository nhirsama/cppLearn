//  B. Move to the End

#include<bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
using pii = std::pair<i32, i32>;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    std::vector<i32> suf(n + 1);
    for (i32 i = 1; i <= n; i++) {
        suf[i] = suf[i - 1] + v[n - i];
    }
    std::vector<i32> dp(n + 1);
    for (i32 i = 1; i <= n; i++) {
        dp[i] = std::max(dp[i - 1], v[i - 1]);
    }
    for (i32 i = 0; i < n; i++) {
        std::cout << suf[i] + dp[n - i] << ' ';
    }
    std::cout << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
