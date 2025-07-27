//  D. Sum of LDS
//  下午11:37
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
    for (auto &i: v)std::cin >> i;
    int64 max = 0;
    for (auto &i: v) {
        if (i > max) {
            max = i;
            i = 1;
        } else i = -1;
    }
    std::vector<int64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + v[i];
    }
    std::ranges::sort(pre);
    int64 ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += pre[i] * (2 * i - n);
    }
    std::cout << (ans + n * (n + 1) * (n + 2) / 6) / 2 << endl;
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