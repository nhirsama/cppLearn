//  D. Creating a Schedule
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> v(k);
    for (auto &i: v) std::cin >> i;
    std::ranges::sort(v);
    for (i32 i = 0; i < n; i++) {
        if (i & 1) {
            i32 p = i / 2;
            for (i32 j = 0; j < 6; j++) {
                if (j & 1) {
                    std::cout << v[p] << ' ';
                } else {
                    std::cout << v[k - p - 1] << ' ';
                }
            }
            std::cout << endl;
        } else {
            i32 p = i / 2;
            for (i32 j = 0; j < 6; j++) {
                if (j & 1) {
                    std::cout << v[k - p - 1] << ' ';
                } else {
                    std::cout << v[p] << ' ';
                }
            }
            std::cout << endl;
        }
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