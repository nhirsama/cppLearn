//  D. Yet Another Array Problem
//  15:16
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int64 n;
    std::cin >> n;
    std::vector<int64> v(n);
    for (auto &i: v) std::cin >> i;
    int x = 1;
    while (x++) {
        for (auto i: v) {
            if (std::gcd(x, i) == 1) {
                std::cout << x << endl;
                return;
            }
        }
    }
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
