//  B. Game with Colored Marbles
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
    i32 one = 0, tow = 0;
    std::map<i32, i32> m;
    for (i32 i = 1; i <= n; i++) {
        i32 t;
        std::cin >> t;
        m[t]++;
    }
    for (auto [x,y]: m) {
        if (y == 1) one++;
        else tow++;
    }
    std::cout << tow + ((one + 1) / 2) * 2 << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
