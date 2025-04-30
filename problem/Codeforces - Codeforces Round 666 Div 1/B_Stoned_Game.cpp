//  B. Stoned Game
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
    std::vector<i32> v(n);
    i32 sum = 0;
    for (auto &i: v) std::cin >> i, sum += i;
    if (*std::ranges::max_element(v) > (sum / 2)) {
        std::cout << "T\n";
    } else if (sum % 2 == 0) {
        std::cout << "HL\n";
    } else {
        std::cout << "T\n";
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
