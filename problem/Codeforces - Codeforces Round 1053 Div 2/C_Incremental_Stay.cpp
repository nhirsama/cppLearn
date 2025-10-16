//  C. Incremental Stay
//  23:40
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
    std::vector<int64> v(2 * n);
    for (auto &i: v)std::cin >> i;
    std::vector<int64> pre1(2 * n + 1), pre2(2 * n + 1), pre3(2 * n + 1);
    // for (int i = 0; i < 2 * n; i += 2) {
    //     pre2[i + 1] = pre2[i];
    //     pre2[i + 2] = pre2[i + 1] + v[i + 2];
    // }
    for (int i = 0; i < 2 * n; i++) {
        pre1[i + 1] = pre1[i] + v[i];
        pre2[i + 1] = pre2[i];
        if (i & 1) pre2[i + 1] += v[i];
        pre3[i + 1] = pre3[i];
        if (i % 2 == 0) pre3[i + 1] += v[i];
    }
    for (int i = 0; i < n; i++) {
        int64 ans = 0;
        ans += pre1[2 * n] - pre1[2 * n - i - 1];
        ans -= pre1[i + 1];
        if (i & 1) {
            ans -= pre2[2 * n - i - 1] - pre2[i + 1];
            ans += pre3[2 * n - i - 1] - pre3[i + 1];
        } else {
            ans += pre2[2 * n - i - 1] - pre2[i + 1];
            ans -= pre3[2 * n - i - 1] - pre3[i + 1];
        }
        std::cout << ans << ' ';
    }
    std::cout << '\n';
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
