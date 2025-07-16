//  D. Vanya and Triangles
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<std::array<i32, 2>> v(n);
    for (auto &[x, y]: v) std::cin >> x >> y;
    if (n < 3) {
        std::cout << 0 << endl;
        return;
    }
    i32 ans = n * (n - 1) * (n - 2) / 6;
    for (i32 i = 0; i < n; i++) {
        std::map<std::array<i32, 2>, i32> m;
        for (i32 j = i + 1; j < n; j++) {
            i32 x = v[i][0] - v[j][0];
            i32 y = v[i][1] - v[j][1];
            if (x < 0) {
                x = -x, y = -y;
            } else if (x == 0 && y < 0) {
                y = -y;
            }
            i32 gcd = std::gcd(x, y);
            x /= gcd;
            y /= gcd;
            m[{x, y}]++;
        }
        for (auto [x, y]: m) {
            ans -= y * (y - 1) / 2;
        }
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}