//
// Created by zxy15 on 25-5-20.
//
#include <bits/stdc++.h>
using i32 = int;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(m);
    for (auto &i: v) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < s.size(); j++) if ((s[j] - '0')) i |= 1 << j;
    }
    i32 rkg, rks, rkb, pg, ps, pb;
    std::cin >> rkg >> rks >> rkb >> pg >> ps >> pb;
    for (i32 i = 1; i < 1 << n; i++) {
        i32 t = __builtin_popcount(i);
        if (10 <= t && t <= 13) {
            std::vector<i32> ac(m);
            for (i32 j = 0; j < m; j++) {
                ac[j] = __builtin_popcount(i & v[j]);
            }
            std::ranges::sort(ac, std::greater<i32>());
            if (ac[rkg - 1] == pg && ac[rks - 1] == ps && ac[rkb - 1] == pb) {
                std::cout << t << '\n';
                for (i32 k = 0; k < n; k++) {
                    if ((i >> k) & 1) {
                        std::cout << k + 1 << ' ';
                    }
                }
                std::cout << '\n';
                return 0;
            }
        }
    }
    std::cout << -1 << std::endl;
}
