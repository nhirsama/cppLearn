//  C. Reverse XOR
//  19:28
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
    bool f = false;
    int t = 0;
    for (int i = 30; ~i; i--) {
        if (n >> i & 1) {
            for (; t < 30; t++) {
                if (n >> t & 1) break;
            }
            f = true;
            if (i == t) {
                std::cout << "NO\n";
                return;
            }
        }
        if (f) {
            if (((n >> i) & 1) != (n >> t & 1)) {
                std::cout << "NO\n";
                return;
            }
            t++;
        }
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
