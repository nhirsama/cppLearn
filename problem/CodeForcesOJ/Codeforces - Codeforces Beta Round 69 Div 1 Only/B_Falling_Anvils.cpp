//  B. Falling Anvils
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using f64 = double;

void nhir() {
    i32 a, b;
    std::cin >> a >> b;
    if (a == 0 && b == 0) {
        std::cout << 1 << endl;
        return;
    }
    if (a == 0) {
        std::cout << 0.5 << '\n';
        return;
    };
    if (b == 0) {
        std::cout << 1 << '\n';
        return;
    };
    f64 s = 0;
    if (1.0 * b / a < 1.0 / 4) {
        s = 2.0 * b * b;
        std::cout << std::format("{:.10f}\n", 1.0 - s / (a * b * 2));
    } else {
        s = a * a / 8.0;
        std::cout << std::format("{:.10f}\n", (s + a * b) / (a * b * 2));
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
