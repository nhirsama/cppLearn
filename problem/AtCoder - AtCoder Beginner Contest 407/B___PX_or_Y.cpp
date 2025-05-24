//  B - P(X or Y)
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
using pii = std::pair<int, int>;

void nhir() {
    std::vector<pii> v;
    for (i32 i = 1; i <= 6; i++) {
        for (i32 j = 1; j <= 6; j++) {
            v.push_back({i, j});
        }
    }
    i32 x, y;
    std::cin >> x >> y;
    i32 ans = 0;
    for (auto &[a, b]: v) {
        if (a + b >= x || std::abs(a - b) >= y) ans++;
    }
    printf("%.20f", 1.0 * ans / 36);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}