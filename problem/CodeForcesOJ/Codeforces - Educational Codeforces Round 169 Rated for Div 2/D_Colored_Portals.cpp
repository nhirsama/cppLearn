//  D. Colored Portals
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, q;
    std::cin >> n >> q;
    const std::string base[] = {"BG", "BR", "BY", "GR", "GY", "RY"};
    std::vector pre(n + 2, std::vector<i32>(6, 0x3f3f3f3f));
    std::vector suf(n + 2, std::vector<i32>(6, 0x3f3f3f3f));
    std::vector<i32> v(n + 1);
    for (i32 i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        v[i] = find(base, base + 6, s) - base;
    }
    for (i32 i = 1; i <= n; i++) {
        for (i32 j = 0; j < 6; j++) {
            pre[i][j] = (v[i] == j ? i : pre[i - 1][j]);
        }
    }
    for (i32 i = n; i; i--) {
        for (i32 j = 0; j < 6; j++) {
            suf[i][j] = (v[i] == j ? i : suf[i + 1][j]);
        }
    }
    while (q--) {
        i32 x, y;
        std::cin >> x >> y;
        i32 ans = 0x3f3f3f3f;
        for (i32 i = 0; i < 6; i++) {
            if (v[x] + i != 5 && i + v[y] != 5) {
                ans = std::min(ans, abs(x - pre[x][i]) + abs(pre[x][i] - y));
                ans = std::min(ans, abs(x - suf[x][i]) + abs(suf[x][i] - y));
            }
        }
        if (ans >= 0x3f3f3f3f / 2) ans = -1;
        std::cout << ans << endl;
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
