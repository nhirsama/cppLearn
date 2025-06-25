//  B. Shrinking Array
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    i32 sing = v[1] - v[0];
    for (i32 i = 0; i < n - 1; i++) {
        if (std::abs(v[i + 1] - v[i]) <= 1) {
            std::cout << 0 << endl;
            return;
        }
    }
    for (i32 i = 0; i < n - 1; i++) {
        if ((v[i + 1] - v[i]) < 0 != sing < 0) {
            std::cout << 1 << endl;
            return;
        }
    }
    std::cout << -1 << endl;
//    std::map<i32, std::set<i32>> ms;
//    for (i32 i = 0; i < n; i++) {
//        ms[v[i] - 1].insert(i);
//        ms[v[i]].insert(i);
//        ms[v[i] + 1].insert(i);
//    }
//    i32 min = inf_i64;
//    for (i32 i = 0; i < n; i++) {
//        for (auto j: ms[v[i]]) {
//            if (i == j) continue;
//            min = std::min(min, std::abs(i - j));
//        }
//    }
//    if (min == inf_i64) {
//        std::cout << -1 << endl;
//        return;
//    }
//    std::cout << min - 1 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}