//  B - You're a teapot
//  14:16
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    std::string s;
    std::cin >> s;
    double ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 't') continue;
        int cnt = 0;
        for (int j = i; j < s.size(); j++) {
            if (s[j] == 't') cnt++;
            if (j - i + 1 >= 3) {
                ans = std::max((cnt - 2) * 1.0 / (j - i - 1), ans);
            }
        }
    }
    // std::cout << ans << endl;
    printf("%.17f", ans);
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
