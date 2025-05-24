//  A - Approximation
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 a, b;
    std::cin >> a >> b;
    i32 m = a / b;
    if ((1.0 * a / b - m) > std::abs(1.0 * a / b - m - 1)) m++;
    std::cout << m << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}