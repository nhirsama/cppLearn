//  A. Theatre Square
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 n, m, a;
    std::cin >> n >> m >> a;
    i32 s;
    if (n % a == 0) s = n / a;
    else s = n / a + 1;
    i32 s2;
    if (m % a == 0) s2 = m / a;
    else s2 = m / a + 1;
    std::cout << s * s2;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}