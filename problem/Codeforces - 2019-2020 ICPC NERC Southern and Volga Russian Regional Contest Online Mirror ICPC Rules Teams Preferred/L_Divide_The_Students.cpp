//  L. Divide The Students
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 a, b, c;
    std::cin >> a >> b >> c;
    std::array<i32, 3> cnt{};
    if (a >= c) {
        cnt[0] = (a + 1) / 2;
        cnt[2] = a / 2;
        cnt[1] = c;
    } else {
        cnt[1] = (c + 1) / 2;
        cnt[2] = c / 2;
        cnt[0] = a;
    }
    i32 max = std::max(cnt[0], cnt[1]);
    for (i32 i = 0; i < 3; i++) {
        i32 j = max - cnt[i];
        cnt[i] = max;
        b = std::max(0ll, b - j);
    }
    if (b == 0) {
        std::cout << max << endl;
    } else {
        std::cout << max + b / 3 + (b % 3 != 0) << endl;
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