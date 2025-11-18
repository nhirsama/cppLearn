//  C. Range Operation
//  10:21
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
    for (auto &i: v) std::cin >> i;
    std::vector<int64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + v[i];
    }
    int64 min = 0;
    int64 ans = 0;
    for (int64 i = 0; i < n; i++) {
        min = std::min(i * i + 3 * i + 2 - pre[i + 1], min);
        ans = std::max(ans, pre[n] + i * i + 3 * i + 2 - pre[i + 1] - min);
    }
    std::cout << ans << endl;
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
