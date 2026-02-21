//  Mike security is better than NASA security.
//  17:09
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr i32 mod = 1ll *
                    // 3 *
                    // 3 *
                    // 3 *
                    // 73 *
                    // 173 *
                    // 593 *
                    // 1451 *
                    // 17971 *
                    998244353 *
                    1;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

void nhir() {
    auto get = [&](i32 a)-> i32 {
        return a * (a + 1) * (2 * a + 1) / 6;
    };
    i32 a, b;
    std::cin >> a >> b;
    a %= 251024;
    b %= 251024;
    if (b >= a) std::cout << (get(b) - get(a - 1)) % 998224353 << endl;
    else std::cout << 0 << endl;
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