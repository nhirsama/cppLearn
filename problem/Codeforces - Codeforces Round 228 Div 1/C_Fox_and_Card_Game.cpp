//  C. Fox and Card Game
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
    i32 ci = 0, ji = 0;
    std::vector<i32> even;
    for (i32 i = 0; i < n; i++) {
        i32 t;
        std::cin >> t;
        if (t & 1) {
            i32 mid = t / 2 + 1;
            for (i32 j = 1; j <= t; j++) {
                i32 x;
                std::cin >> x;
                if (j < mid) ci += x;
                else if (j > mid) ji += x;
                else even.push_back(x);
            }
        } else {
            for (i32 j = 1; j <= t; j++) {
                i32 x;
                std::cin >> x;
                if (j <= t / 2) ci += x;
                else ji += x;
            }
        }
    }
    std::ranges::sort(even,std::greater<>());
    for (i32 i = 0; i < even.size(); i++) {
        if (i & 1) {
            ji += even[i];
        } else ci += even[i];
    }
    std::cout << ci << ' ' << ji << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
