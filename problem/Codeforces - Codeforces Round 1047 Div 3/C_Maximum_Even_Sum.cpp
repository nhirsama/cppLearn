//  C. Maximum Even Sum
//  17:10
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int64 a, b;
    std::cin >> a >> b;
    int64 max = -1;
    for (int64 t = 1; t * t <= b; t++) {
        if (b % t == 0) {
            int64 tm = b / t + a * t;
            if (tm % 2 == 0)
                max = std::max(tm, max);
            tm = t + a * (b / t);
            if (tm % 2 == 0)
                max = std::max(tm, max);
        }
    }
    std::cout << max << enld;
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
