//  C. Uninteresting Number
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    std::string s;
    std::cin >> s;
    i32 ans = 0, tow = 0, the = 0;
    for (auto i: s) {
        if (i == '2') tow++;
        if (i == '3') the++;
        ans += i - '0';
    }

    for (i32 i = 0; i <= std::min(8ll, tow); i++) {
        for (i32 j = 0; j <= std::min(8ll, the); j++) {
            if ((ans + 2 * i + 6 * j) % 9 == 0) {
                std::cout << "YES\n";
                return;
            }
        }
    }
    // if (ans % 9 == 0) {
    //     std::cout << "YES\n";
    //     return;
    // }
    // if (ans % 9 == 1 && ((tow >= 4) || (tow >= 1 && the >= 1))) {
    //     std::cout << "YES\n";
    //     return;
    // }
    // if (ans % 9 == 2 && ((tow >= 8) ||())) {
    //     std::cout << "YES\n";
    //     return;
    // }
    // if (ans % 9 == 3 && ((the >= 1))) {
    //     std::cout << "YES\n";
    //     return;
    // }
    // if (ans % 9 == 5 && ((tow >= 2))) {
    //     std::cout << "YES\n";
    //     return;
    // }
    // if (ans % 9 == 6 && ((the >= 2))) {
    //     std::cout << "YES\n";
    //     return;
    // }
    // if (ans % 9 == 7 && ((tow >= 1))) {
    //     std::cout << "YES\n";
    //     return;
    // }
    // if (ans % 9 == 8 && ((tow >= 2 && the >= 1))) {
    //     std::cout << "YES\n";
    //     return;
    // }
    // std::cout << ans << endl;
    std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
