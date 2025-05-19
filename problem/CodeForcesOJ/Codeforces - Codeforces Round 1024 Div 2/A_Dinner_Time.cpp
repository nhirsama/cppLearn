//  A. Dinner Time
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, m, p, q;
    std::cin >> n >> m >> p >> q;
    // if (p == 1 && n * q == m) {
    //     std::cout << "YES\n";
    //     return;
    // } else if (p == 1) {
    //     std::cout << "NO\n";
    //     return;
    // }
    std::cout << (n % p == 0 && n / p * q != m ? "NO\n" : "YES\n");
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
