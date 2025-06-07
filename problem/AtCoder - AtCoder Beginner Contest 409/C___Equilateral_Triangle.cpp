//  C - Equilateral Triangle
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 l, n;
    std::cin >> n >> l;
    if (l % 3) {
        std::cout << 0 << endl;
        return;
    }
    std::vector<i32> v(n);
    for (i32 i = 1; i < n; i++) std::cin >> v[i];
    i32 r = l / 3;
    std::vector<i32> cnt(l);
    i32 now = 0;
    cnt[0]++;
    for (i32 i = 1; i < n; i++) {
        now += v[i];
        cnt[now % l]++;
    }
    i32 ans = 0;
    for (i32 i = 0; i < r; i++) {
        ans += cnt[i] * cnt[i + r] * cnt[i + r + r];
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) nhir();
    return 0;
}
