//  P10532 [XJTUPC 2024] 筛法
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    i32 ans = 0;
    // for (i32 i = 1; i <= n; i++) {
    //     for (i32 j = 1; j <= n; j++) {
    //         if (std::gcd(i, j) == 1) {
    //             ans += n / std::max(i, j);
    //         }
    //     }
    // }
    std::cout << n * n << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
