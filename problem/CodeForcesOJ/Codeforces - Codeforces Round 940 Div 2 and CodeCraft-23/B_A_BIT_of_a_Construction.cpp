//  B. A BIT of a Construction
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    if (__builtin_popcount(k + 1) == 1) {
        std::cout << k << ' ';
        n--;
        while (n--) {
            std::cout << 0 << ' ';
        }
        std::cout << endl;
        return;
    } else {
        auto highbit = [](i32 x) -> i32 {
            while (x != (x & -x)) x -= (x & -x);
            return x;
        };
        if (n == 1) {
            std::cout << k << endl;
            return;
        } else {
            std::cout << highbit(k) - 1 << ' ';
            std::cout << k - highbit(k) + 1 << ' ';
            n -= 2;
            while (n--) std::cout << 0 << ' ';
            std::cout << endl;
            return;
        }
    }
//    auto lowbit = [](i32 x) -> i32 {
//        return x & -x;
//    };
//    while (n--) {
//        if (n == 0) {
//            std::cout << k << endl;
//        } else {
//            std::cout << lowbit(k) << ' ';
//            k -= lowbit(k);
//        }
//    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}