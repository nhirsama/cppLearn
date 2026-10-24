//  B - Polyline
//  20:12
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for (auto &i: v) std::cin >> i;
    int ans = 0;
    if (v[0] == k) ans++;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] < k && v[i] >= k) ans++;
        else if (v[i - 1] > k && v[i] <= k) ans++;
    }
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