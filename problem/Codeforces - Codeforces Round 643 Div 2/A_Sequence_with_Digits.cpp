//  A. Sequence with Digits
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 a, k;
    std::cin >> a >> k;
    for (i32 i = 1; i < k; i++) {
        i32 t = a;
        i32 min = 9, max = 0;
        while (t) {
            min = std::min(min, t % 10);
            max = std::max(max, t % 10);
            t /= 10;
        }
        a += min * max;
        if (!min * max) break;
    }
    std::cout << a << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
