//  A. Roman and Browser
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    i32 ans = 0;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    i32 a = std::count(v.begin(), v.end(), 1);
    i32 b = std::count(v.begin(), v.end(), -1);
    for (i32 i = 0; i < k; i++) {
        i32 bt = b, at = a;
        for (i32 j = i; j < n; j += k) {
            v[j] == 1 ? at-- : bt--;
        }
        ans = std::max(ans, std::abs(at - bt));
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
