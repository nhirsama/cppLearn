//  Bitwise Puzzle
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    int64 a, b, c;
    std::cin >> a >> b >> c;
    std::vector<int> op;
    auto swap = [&]() {
        op.push_back(3);
        op.push_back(4);
        op.push_back(3);
        a ^= b ^= a ^= b;
    };
    if (a && b) {
        if (b == 0) swap;
        if ((a | c) != c) {
//            bool f = false;
//            for (int i = 0; i < 32; i++) {
//
//            }
        }
        while ((a | c) != c) {
            a <<= 1;
            op.push_back(1);
        }
        while (b != 1) {
            b >>= 1;
            op.push_back(2);
        }
        while (a != c) {

        }
    } else {
        std::cout << -1 << enld;
    }
//    for (int i = 0; i < 32; i++) {
//        for (int j = 0; j < 32; j++) {
//            if (((a << i) ^ (b >> j)) == c) {
//
////                std::cout << "YES\n";
//                return;
//            }
//        }
//    }
//    std::cout << -1 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}