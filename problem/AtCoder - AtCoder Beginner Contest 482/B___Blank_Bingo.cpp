//  B - Blank Bingo
//  20:21
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    std::vector<std::string> v(5, std::string());
    for (auto &s: v) std::cin >> s;
    int ans = 5;
    int lx = 0, rx = 0;
    for (int i = 0; i < 5; i++) {
        int ii = 0, jj = 0;
        for (int j = 0; j < 5; j++) {
            if (v[i][j] == '.') ii++;
            if (v[j][i] == '.') jj++;
            if (i == j && v[i][j] == '.') rx++;
            if (i + j == 4 && v[i][j] == '.') lx++;
        }
        ans = std::min(ans, ii);
        ans = std::min(ans, jj);
    }

    ans = std::min(ans, rx);
    ans = std::min(ans, lx);
    std::cout << ans << enld;
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
