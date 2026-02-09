//  B - Exam Passers
//  20:33
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    i32 n, l, r;
    std::cin >> n >> l >> r;
    i32 ans = -1, xh = -1;
    for (int i = 1; i <= n; i++) {
        i32 t;
        std::cin >> t;
        if (t >= l && t <= r) {
            if (t > ans) {
                ans = t;
                xh = i;
            }
        }
    }
    std::cout << xh << endl;
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
