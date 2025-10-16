//  Distant Control
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    int64 n, a;
    std::cin >> n >> a;
    std::string s;
    std::cin >> s;
    std::vector<std::array<int64, 2>> pre(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            pre[i + 1][0] = pre[i][0] + 1;
            pre[i + 1][1] = pre[i][1];
        } else {
            pre[i + 1][0] = pre[i][0];
            pre[i + 1][1] = pre[i][1] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i >= a && pre[i + 1][0] - pre[i + 1 - a - 1][0] == a + 1) {
            std::cout << n << endl;
            return;
        } else if (i >= a - 1 && pre[i + 1][1] - pre[i + 1 - a][1] == a) {
            std::cout << n << enld;
            return;
        }
    }
    std::cout << pre[n][1] << endl;
//    int64 cntmin = inf_i64;
//    for (int i = a; i < n; i++) {
//        cntmin = std::min(cntmin, std::min(pre[i + 1][0] - pre[i - a][0], pre[i + 1][1] - pre[i - a][1]));
//    }
//    std::cout << n - cntmin << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}