//  A. Gellyfish and Tricolor Pansy
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'

void nhir() {
    // std::list<i32> li;
    i32 a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << (std::min(a, c) < std::min(b, d) ? "Flower\n" : "Gellyfish\n");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
