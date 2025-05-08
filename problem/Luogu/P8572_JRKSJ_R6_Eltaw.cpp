//  P8572 [JRKSJ R6] Eltaw
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using pii = std::pair<int, int>;

void nhir() {
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector num(k, std::vector<i32>(n + 1));
    for (auto &i: num) {
        for (i32 j = 1; j <= n; j++) {
            std::cin >> i[j];
            i[j] += i[j - 1];
        }
    }
    std::map<pii, i32> m;
    if (true) {
        while (q--) {
            int l, r;
            std::cin >> l >> r;
            if (m.find({l, r}) != m.end()) {
                std::cout << m[{l, r}] << endl;
            } else {
                i32 max = 0;
                for (auto &i: num) {
                    max = std::max(max, i[r] - i[l - 1]);
                }
                m[{l, r}] = max;
                std::cout << max << endl;
            }
        }
    }
    // else {
    //     for (int l = 1; l <= n; l++) {
    //         for (int r = l; r <= n; r++) {
    //             i32 max = 0;
    //             for (auto &i: num) {
    //                 max = std::max(max, i[r] - i[l - 1]);
    //             }
    //             m[{l, r}] = max;
    //         }
    //     }
    //     while (q--) {
    //         int l, r;
    //         std::cin >> l >> r;
    //         std::cout << m[{l, r}] << endl;
    //     }
    // }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
