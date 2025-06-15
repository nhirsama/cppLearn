//  B. Make It Permutation
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
//    if (n & 1) {
    std::cout << 2 * n - 3 << endl;
    for (i32 i = 2; i <= n; i++) {
        std::cout << i << ' ' << 1 << ' ' << i << endl;
    }
    for (i32 i = 1; i < n - 1; i++) {
        std::cout << i << ' ' << i + 1 << ' ' << n << endl;
    }
//    } else {
//        std::cout << 2 * n - 3 << endl;
//        for (i32 i = 2; i <= n; i++) {
//            std::cout << i << ' ' << 1 << ' ' << i << endl;
//        }
//        for (i32 i = 1; i < n - 1; i++) {
//            std::cout << i << ' ' << i + 1 << ' ' << n << endl;
//        }
//    }
}
/*
 1 2 3 4
 2 1 4 3
 3 2 1 4
 4 3 2 1
 */
/*
 1 5 4 3 2
 2 1 5 4 3
 3 2 1 5 4
 4 3 2 1 5
 5 4 3 2 1
 */
/*
 * 1 2 3 4 5 6
 * 2 1 6 5 4 3
 * 3 2 1 6 5 4
 * 4 3 2 1 6 5
 * 5 4 3 2 1 6
 * 6 5 4 3 2 1
 */
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
