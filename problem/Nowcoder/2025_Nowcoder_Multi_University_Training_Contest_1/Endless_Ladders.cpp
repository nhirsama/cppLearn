//  Endless Ladders
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 a, b;
    std::cin >> a >> b;
    i32 t = 0;
    i32 mul = std::abs((a + b) * (a - b));
    if (mul >= 4)t++;
//    for (i32 i = 1; i <= mul / 2; i += 2) {
//        if (2 * i <= mul) t++;
//    }
    t += (mul + 1) / 4;
    std::cout << mul - t - 1 << endl;
//    i32 t = std::max(a, b);
//    std::set<i32> s;
//    for (i32 i = 1; i <= t + 5; i++) {
//        for (i32 j = 1; j <= t + 5; j++) {
//            if (i == j)continue;
//            s.insert(std::abs(i * i - j * j));
//        }
//    }
//    std::vector<i32> v;

//    for (auto i: s) {
//        std::cout << i << ' ';
////        v.push_back(i);
//    }

//    std::cout << std::ranges::upper_bound(v, std::abs((a + b) * (a - b))) - v.begin() << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}