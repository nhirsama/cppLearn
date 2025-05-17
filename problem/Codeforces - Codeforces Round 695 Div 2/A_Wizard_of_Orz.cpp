//  A. Wizard of Orz
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
    if (n == 1) {
        std::cout << 9 << endl;
        return;
    }
    if (n == 2) {
        std::cout << 98 << endl;
        return;
    }
    if (n > 2) {
        std::cout << 98;
        for (i32 i = 2; i < n; i++) {
            std::cout << ((i+7) % 10);
        }
    }
    // if (n <= 9) {
    //     for (i32 i = 0; i < n; i++) {
    //         std::cout << 9 - (i % 10);
    //     }
    // } else {
    //     for (i32 i = 0;i<9;i++) {
    //         std::cout << 9 - (i % 10);
    //     }
    //     for (i32 i = 9;i<n;i++) {
    //         std::cout<<((i+3)%10);
    //     }
    //     // if (n & 1) {
    //     //     for (i32 i = 0; i <= n / 2; i++) {
    //     //         std::cout << 9 - (i % 10);
    //     //     }
    //     //     for (i32 i = n / 2 - 1; ~i; i--) {
    //     //         std::cout << 9 - (i % 10);
    //     //     }
    //     // } else {
    //     //
    //     //     // for (i32 i = 0; i < n / 2; i++) {
    //     //     //     std::cout << 9 - (i % 10);
    //     //     // }
    //     //     // for (i32 i = n / 2 - 1; ~i; i--) {
    //     //     //     std::cout << 9 - (i % 10);
    //     //     // }
    //     // }
    std::cout << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
