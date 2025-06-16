//  P12833 [蓝桥杯 2025 国 B] 斐波那契字符串
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr int N = 1e5 + 10;
i32 v0[N], v1[N], cnt[N];

void init() {
    v0[1] = v1[2] = 1;
    for (i32 i = 3; i < N - 5; i++) {
        v0[i] = (v0[i - 1] + v0[i - 2]) % mod;
        v1[i] = (v1[i - 1] + v1[i - 2]) % mod;
        cnt[i] = (v1[i - 2] * v0[i - 1] % mod + cnt[i - 1] + cnt[i - 2]) % mod;
    }
}

void nhir() {
    i32 n;
    std::cin >> n;
    std::cout << cnt[n] << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    init();
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
