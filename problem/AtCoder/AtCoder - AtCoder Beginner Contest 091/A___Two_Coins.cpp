//  Two Coins
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i64 a, b, c;
    std::cin >> a >> b >> c;
    if (a + b < c) {
        std::cout << "No" << endl;
    } else {
        std::cout << "Yes" << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}