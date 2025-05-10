//  A - Is it rated?
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 r, x;
    std::cin >> r >> x;
    if (x == 1) {
        std::cout << ((1600 <= r && r <= 2999 ? "Yes\n" : "No\n"));
    } else {
        std::cout << ((1200 <= r && r <= 2399 ? "Yes\n" : "No\n"));
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
