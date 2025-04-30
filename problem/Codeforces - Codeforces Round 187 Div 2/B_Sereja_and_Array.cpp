//  B. Sereja and Array
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector<i32> v(n + 1);
    for (i32 i = 1; i <= n; i++) {
        std::cin >> v[i];
    }
    i32 add = 0;
    while (m--) {
        i32 op;
        std::cin >> op;
        if (op == 1) {
            i32 p, y;
            std::cin >> p >> y;
            v[p] = y - add;
        } else if (op == 2) {
            i32 y;
            std::cin >> y;
            add += y;
        } else {
            i32 p;
            std::cin >> p;
            std::cout << v[p] + add << endl;
        }
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
