//  B. Even Array
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    i32 odd = 0, even = 0;
    for (i32 i = 0; i < n; i++) {
        if ((i % 2 == 0) && (v[i] % 2 == 1)) odd++;
        if ((i % 2 == 1) && (v[i] % 2 == 0)) even++;
    }
    //std::cout << odd << ' ' << even << endl;
    if (odd != even) {
        std::cout << -1 << endl;
    } else {
        std::cout << odd << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}