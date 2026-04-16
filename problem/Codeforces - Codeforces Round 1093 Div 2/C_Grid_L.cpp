//  C. Grid L
//  08:49
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    i32 p, q;
    std::cin >> p >> q;
    i32 tot = p + 2 * q;
    auto get = [](i32 a, i32 b) -> i32 {
        return (a + 1) * b + (b + 1) * a;
    };
    // 2*a*b+a+b == p+q*2
    // for (i32 i = 1; i <= std::sqrt(mul); i++) {
    //     if (mul % i == 0) {
    //         if (get(i, mul) == p + q * 2) {
    //             std::cout << i << ' ' << mul << endl;
    //             return;
    //         }
    //     }
    // }
    // i32 ansa = 0, ansb = inf_i64;
    for (int i = 1; i < 2e4; i++) {
        int b = (tot - i) / (2 * i + 1);
        if (b == 0) continue;
        if (get(i, b) == tot) {
            if (p < std::abs(i-b)) continue;
            // if (std::abs(ansa - ansb) > std::abs(i - b)) {
            //     ansa = i, ansb = b;
            // }
            std::cout << i << ' ' << b << endl;
            return;
        }
    }
    // if (ansa != 0 && ansb != -inf_i64) {
    //     std::cout << ansa << ' ' << ansb << endl;
    //     return;
    // }
    std::cout << -1 << endl;
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
