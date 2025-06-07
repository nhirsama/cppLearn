//  B - Citation
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    std::ranges::sort(v);
    i32 ans = 0;
    for (i32 i = 0; i <= n; i++) {
        i32 cnt = v.end() - std::ranges::lower_bound(v, i);
        if (cnt >= i) ans = std::max(ans, i);
    }
    std::cout << ans << endl;
    // for (i32 i = n - 1; i >= 0; i--) {
    //     if ((n - i) >= i) {
    //         std::cout << v[i];
    //         return;
    //     }
    // }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}
