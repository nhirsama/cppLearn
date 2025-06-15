//  A. Shashliks
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 k, a, b, x, y;
    std::cin >> k >> a >> b >> x >> y;
    i32 ans = 0;
    if (x < y) {
        if (k >= a) {
            i32 t = k - a + x;
            ans += t / x;
            k = a + t % x - x;
        }
        if (k >= b) {
            i32 t = k - b + y;
            ans += t / y;
            k = b + t % y - y;
        }
    } else {
        if (k >= b) {
            i32 t = k - b + y;
            ans += t / y;
            k = b + t % y - y;
        }
        if (k >= a) {
            i32 t = k - a + x;
            ans += t / x;
            k = a + t % x - x;
        }
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