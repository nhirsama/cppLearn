//  C. Subset Multiplication
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    int n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    std::vector<i32> g;
    for (i32 i = n - 1; i; i--) {
        if (v[i] % v[i - 1]) {
            i32 gcd = std::gcd(v[i - 1], v[i]);
            g.push_back(v[i - 1] / gcd);
            v[i - 1] = gcd;
        }
//        v[i - 1] /= std::gcd(v[i - 1], v[i]);
    }
    i32 lcm = 1;
    for (auto i: g) {
        lcm = std::lcm(lcm, i);
    }
    std::cout << lcm << endl;
//    i32 gcd = 0;
//    for (i32 i = 1; i < n; i++) {
//        if (v[i] % v[i - 1]) gcd = std::gcd(v[i], gcd);
//    }
//    std::cout << lcm << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}