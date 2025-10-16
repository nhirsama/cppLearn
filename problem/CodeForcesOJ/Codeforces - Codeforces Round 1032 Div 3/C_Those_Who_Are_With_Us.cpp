//  C. Those Who Are With Us
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    i32 max = 0;
    std::vector v(n, std::vector<i32>(m));
    for (auto &i: v) {
        for (auto &j: i) std::cin >> j, max = std::max(max, j);
    }
    std::map<i32, i32> hh, ll;
    i32 cnt = 0;
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < m; j++) {
            if (v[i][j] == max) hh[j]++, ll[i]++, cnt++;
        }
    }
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < m; j++) {
            if (hh[j] + ll[i] == cnt + (v[i][j] == max)) {
                std::cout << max - 1 << endl;
                return;
            }
        }
    }
    // for (auto [xx,xc]: hh) {
    //     for (auto [yy,yc]: ll) {
    //         if (xc + yc == cnt) {
    //             std::cout << max - 1 << endl;
    //             return;
    //         }
    //     }
    // }
    // if (hh.size() <= 2 || ll.size() <= 2) {
    //     std::cout << max - 1 << endl;
    //     return;
    // }
    std::cout << max << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
