//  A. Wonderful Sticks
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    i32 xy = 0;
    for (auto c: s)if (c == '<') xy++;
    i32 l = xy, r = xy + 2;
    std::cout << xy + 1 << ' ';
    for (auto i: s) {
        if (i == '<') {
            std::cout << l-- << ' ';
        } else {
            std::cout << r++ << ' ';
        }
    }
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
