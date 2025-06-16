//  P12832 [蓝桥杯 2025 国 B] 数字轮盘
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    k %= n;
    if (k == 0) {
        std::cout << 0 << endl;
        return;
    }
    k = n - k;
    if (n % 2 == 0 && k % 2 == 1) {
        std::cout << -1 << endl;
        return;
    }
    while (k & 1) k += n;
    std::cout << k / 2 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
