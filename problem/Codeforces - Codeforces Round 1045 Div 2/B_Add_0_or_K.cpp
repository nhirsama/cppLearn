//  B. Add 0 or K
//  16:31
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int64 a, k;
    std::cin >> a >> k;
    std::vector<int64> v(a);
    int64 gcd = 0;
    for (auto &i: v) std::cin >> i, gcd = std::gcd(gcd, i);
    if (gcd > 1) {
        for (auto i: v) {
            std::cout << i << ' ';
        }
        std::cout << enld;
        return;
    }
    for (int g = 2;; g++) {
        if (std::gcd(g, k) != 1) continue;
        for (auto &i: v) {
            if (std::gcd(g, i) != 1) continue;
            while (i % g != 0) i += k;
        }
        for (auto i: v) {
            std::cout << i << ' ';
        }
        std::cout << enld;
        return;
    }
    // if (k & 1) {
    //     for (auto &i: v) {
    //         if (i & 1) i += k;
    //     }
    // } else {
    //     int t = 3;
    //     for (int i = 3; i <= k; i += 2) {
    //         if (k % i != 0) {
    //             t = i;
    //             break;
    //         }
    //     }
    //     for (auto &i: v) {
    //         while (i % t != 0) i += k;
    //     }
    // }
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << enld;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}
