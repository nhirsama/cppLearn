//  E. Martian Food
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using f32 = long double;

void nhir() {
    f32 r1, r2;
    i32 n;
    std::cin >> r1 >> r2 >> n;
    f32 rr1 = 1 / (r1 - r2);
    f32 rr2 = -1 / r1 + 1 / r2 + rr1;
    f32 rr3 = rr1;
    for (i32 i = 1; i < n; i++) {
        rr3 = rr1;
        rr1 = rr2;
        rr2 = 2 * (-1 / r1 + 1 / r2 + rr1) - rr3;
    }
    std::cout << std::format("{:.10Lf}\n", 1 / rr2);
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
