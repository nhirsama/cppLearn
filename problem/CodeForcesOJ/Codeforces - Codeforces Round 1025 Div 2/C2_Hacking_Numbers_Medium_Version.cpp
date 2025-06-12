//  C2. Hacking Numbers (Medium Version)
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;

void check() {
    i32 input;
    std::cin >> input;
    if (input == -1) {
        std::exit(0);
    }
}

void nhir() {
    i32 x;
    std::cin >> x;
    std::cout << std::format("mul 999999999") << std::endl;
    check();
    std::cout << std::format("digit") << std::endl;
    check();
//    std::cout << std::format("digit") << std::endl;
//    check();

    if (x != 81) {
        std::cout << std::format("add {}", x - 81) << std::endl;
        check();
    }
    std::cout << std::format("!") << std::endl;
    check();
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}