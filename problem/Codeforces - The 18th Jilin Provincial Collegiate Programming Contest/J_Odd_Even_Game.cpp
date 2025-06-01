//  J. Odd-Even Game
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 a, b;
    std::cin >> a >> b;
    if (a & 1) {
        std::cout << 1 + (bool) (a <= b) << endl;
    } else {
        std::cout << 1 + (bool) (b <= a) << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}