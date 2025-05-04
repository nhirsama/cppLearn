//  D - Goin' to the Zoo
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
    std::vector zoo(n, std::vector<i32>());
    std::vector<i32> w(n);
    for (auto &i: w) std::cin >> i;
    for (i32 i = 0; i < m; i++) {
        i32 k;
        std::cin >> k;
        for (i32 j = 0; j < k; j++) {
            i32 t;
            std::cin >> t;
            zoo[--t].push_back(i);
        }
    }
    i32 ans = 0x3f3f3f3f3f3f3f3f;
    for (i32 k = 0; k < (1 << n * 2); k++) {
        i32 ma = 0;
        std::vector<i32> dp(m);
        for (i32 i = 0; k >> i; i++) {
            if (k >> i & 1) {
                ma += w[i % n];
                for (auto j: zoo[i % n]) {
                    dp[j]++;
                }
            }
        }
        bool flag = true;
        for (auto i: dp) {
            if (i < 2) {
                flag = false;
                break;
            }
        }
        if (flag) ans = std::min(ma, ans);
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
