//  C. gcd
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 a, b;
    std::cin >> a >> b;
    // if (a == 1 && b > 1) {
    //     std::cout << b << endl;
    //     return;
    // }
    i32 gcd = std::gcd(a, b);
    if (gcd == 1 && b != 1) {
        std::cout << b << endl;
        return;
    }
    if (b == 1) {
        std::cout << -1 << endl;
        return;
    }
    while (gcd > 1) {
        b = b / gcd;
        if (a == b || b == 1) {
            std::cout << -1 << endl;
            return;
        }
        gcd = std::gcd(a, b);
    }
    std::cout << b << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
