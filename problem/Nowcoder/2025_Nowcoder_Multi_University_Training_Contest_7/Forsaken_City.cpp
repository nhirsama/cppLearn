//  Forsaken City
//  下午12:04
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

void nhir() {
    int64 n;
    std::cin >> n;
    std::vector<int64> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector<int64> pre_max(n + 1);
    for (int i = 0; i < n; i++) {
        pre_max[i + 1] = std::max(pre_max[i], v[i]);
    }
    int64 ans = 0;
    for (int i = 1; i < n; i++) {
        ans = std::max(ans, std::abs(pre_max[i] - v[i]));
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