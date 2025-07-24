//  Determinant of 01-Matrix
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    int64 n;
    std::cin >> n;
    std::cout << 2 << enld;
    std::cout << 1 << ' ' << 0 << '\n' << 0 << ' ' << n << enld;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i == j) {
//                if (i == n - 1) {
//                    std::cout << n << ' ';
//                } else std::cout << 1 << ' ';
//            } else {
//                std::cout << 0 << ' ';
//            }
//        }
//        std::cout << enld;
//    }
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}