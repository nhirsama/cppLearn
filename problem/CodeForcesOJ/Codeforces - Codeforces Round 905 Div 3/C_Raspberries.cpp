//  C. Raspberries
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> v(n);
    i32 ans = inf_i64;
    i32 tt1 = 0, tt2 = 0;
    for (i32 i = 0; i < n; i++) {
        std::cin >> v[i];
        v[i] %= k;
        if (k == 4 && v[i] == 1) tt1++;
        if (k == 4 && v[i] == 2) tt2++;

        ans = std::min(ans, (k - v[i]) % k);
    }
    if (tt1 >= 2) ans = std::min(2ll, ans);
    if (tt2 >= 2) ans = std::min(0ll, ans);
    if (tt2 >= 1 && tt1 >= 1) ans = std::min(1ll, ans);
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}