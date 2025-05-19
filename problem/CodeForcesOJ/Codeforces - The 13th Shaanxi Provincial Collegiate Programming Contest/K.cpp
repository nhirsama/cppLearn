//
// Created by ling on 25-5-13.
//
//  K. Welfare
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, m, x, y;
    std::cin >> n >> m >> x >> y;
    i32 ans = 0;
    for (i32 i = 0; i <= n; i++) {
        if ((((double) x) / (i + 1)) > y) {
            ans = std::max(ans, (i32) (n - i) * y + x * (i + m != 0));
        } else {
            ans = std::max(ans, (i32) (n - i + m) * y + x * (i != 0));
        }
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
