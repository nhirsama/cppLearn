//  A. Guilty — to the kitchen!
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using f64 = double;
using f128 = long double;
using f32 = float;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n;
    f64 v;
    std::cin >> n >> v;
    std::vector<f64> ai(n), bi(n);
    for (auto &i: ai) std::cin >> i;
    for (auto &i: bi) std::cin >> i;
    f64 c = 1e10;
    for (i32 i = 0; i < n; i++) {
        c = std::min(c, bi[i] / ai[i]);
    }
    f64 ans = 0;
    for (i32 i = 0; i < n; i++) ans += ai[i] * c;
    printf("%.10f\n", std::min(ans, v));
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
