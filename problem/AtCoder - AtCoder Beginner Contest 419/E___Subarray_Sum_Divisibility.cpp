//  E - Subarray Sum Divisibility
//  下午9:03
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    int n, m, l;
    std::cin >> n >> m >> l;
    std::vector<int> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector dp(505, std::vector<int>(505));
    for (int i = 0; i <= 500; i++) {
        dp[0][i] = i;
    }
    
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