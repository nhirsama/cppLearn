//  B. Bitwise Reversion
//  21:14
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int x, y, z;
    std::cin >> x >> y >> z;
    for (int i = 0; i < 30; i++) {
        if (![&]() {
            for (auto a: {0, 1}) {
                for (auto b: {0, 1}) {
                    for (auto c: {0, 1}) {
                        if (((a & b) == ((x >> i) & 1) && ((b & c) == (y >> i & 1)) && ((a & c) == (z >> i & 1)))) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }()) {
            std::cout << "NO\n";
            return;
        };
    }
    std::cout << "YES\n";
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
