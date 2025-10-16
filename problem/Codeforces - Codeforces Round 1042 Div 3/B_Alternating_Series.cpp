//  B. Alternating Series
//  22:41
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int n;
    std::cin >> n;
    if (n & 1) {
        if (n >= 3) {
            for (int i = 0; i < n - 3; i++) {
                if (i & 1) std::cout << 3 << ' ';
                else std::cout << -1 << ' ';
            }
        }
        std::cout << -1 << ' ' << 3 << ' ' << -1 << endl;
    } else {
        if (n >= 2) {
            for (int i = 0; i < n - 2; i++) {
                if (i & 1) std::cout << 3 << ' ';
                else std::cout << -1 << ' ';
            }
        }
        std::cout << -1 << ' ' << 2 << endl;
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
