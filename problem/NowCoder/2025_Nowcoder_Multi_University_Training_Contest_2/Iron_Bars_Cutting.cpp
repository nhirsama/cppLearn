//  Iron Bars Cutting
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
int dp[420][420][420];

void nhir() {
    int n;
    std::cin >> n;
    std::array<int, 420> v;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}