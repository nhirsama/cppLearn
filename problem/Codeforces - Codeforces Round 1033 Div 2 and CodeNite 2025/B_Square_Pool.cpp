//  B. Square Pool
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 t, a;
    std::cin >> t >> a;
    i32 ans = 0;
    for (i32 i = 0; i < t; i++) {
        i32 dx, dy, x, y;
        std::cin >> dx >> dy >> x >> y;
        if (x + y == a) ans++;
    }
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