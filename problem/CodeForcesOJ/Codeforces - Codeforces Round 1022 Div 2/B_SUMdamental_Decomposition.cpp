//  B. SUMdamental Decomposition
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
    if (n == 1 && x == 0) {
        std::cout << -1 << endl;
        return;
    }
    if ((n & 1) && x == 0) {
        std::cout << n + 3 << endl;
        return;
    }
    if ((n & 1) == 0 && x == 1) {
        std::cout << n + 3 << endl;
        return;
    }
    i32 cnt = std::max(n - __builtin_popcountll(x), 0ll);
    if (cnt & 1) cnt++;
    i32 ans = x + cnt;
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
