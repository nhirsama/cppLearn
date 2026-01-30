//  B. Prefix Max
//  17:15
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    i32 max = *std::ranges::max_element(v);
    std::cout << max * n << endl;
    // std::vector<i32> pre(n + 1);
    // i32 sum = 0;
    // for (int i = 0; i < n; i++) {
    //     pre[i + 1] = pre[i] + v[i];
    //     sum += pre[i + 1];
    // }
    // i32 ans = sum;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < i; j++) {
    //         ans = std::max(ans, sum + (v[i] - v[j]) * (j - i + 1));
    //     }
    // }
    // std::cout << ans << endl;
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