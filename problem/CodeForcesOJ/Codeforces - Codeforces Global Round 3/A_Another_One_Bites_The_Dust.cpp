//  A. Another One Bites The Dust
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 a, b, c;
    std::cin >> a >> b >> c;
    i32 min = std::min(a, b);
    a -= min;
    b -= min;
    c += min;
    std::cout << c * 2 + (a != 0) + (b != 0) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) nhir();
    return 0;
}
