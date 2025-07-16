//  B. Jumps
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 x;
    std::cin >> x;
    for (i32 i = 1; i <= x + 1; i++) {
        if (i * (i + 1) / 2 > x) {
            i--;
            std::cout << i + (x - i * (i + 1) / 2) * 2 << endl;
            return;
        }
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
