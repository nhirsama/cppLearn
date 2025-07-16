//  A. Shape Perimeter
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, m, x1 = 0, y1 = 0, x2, y2;
    std::cin >> n >> m;
    std::cin >> x2 >> y2;
    x1 = m, y1 = m;
    for (i32 i = 1; i < n; i++)std::cin >> x2 >> y2, x1 += x2, y1 += y2;
    std::cout << x1 * 2 + y1 * 2 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}