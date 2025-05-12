//  B. The Picky Cat
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (i32 i = 0; i < n; i++) {
        std::cin >> v[i];
        v[i] = std::abs(v[i]);
    }
    i32 t = v[0];
    std::sort(v.begin(), v.end());
    if (v[(n) / 2] >= t) {
        std::cout << "YES\n";
    } else std::cout << "NO\n";
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
