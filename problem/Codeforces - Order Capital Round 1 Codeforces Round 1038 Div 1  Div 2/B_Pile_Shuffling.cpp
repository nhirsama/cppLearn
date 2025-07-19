//  B. Pile Shuffling
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    i32 ans = 0;
    for (i32 i = 0; i < n; i++) {
        i32 a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if (b <= d) ans += std::max(0ll, a - c);
        else ans += b - d + a;
    }
    std::cout << ans << enld;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}