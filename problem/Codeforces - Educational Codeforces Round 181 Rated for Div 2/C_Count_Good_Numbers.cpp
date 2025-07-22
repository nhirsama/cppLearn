//  C. Count Good Numbers
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    int64 a, b;
    std::cin >> a >> b;
    auto get = [](int64 t) -> int64 {
        int64 add = t / 6 + t / 10 + t / 14 + t / 15 + t / 21 + t / 35
                    - t / 30 - t / 42 - t / 70 - t / 105 + t / 210;
        return t - t / 2 - t / 3 - t / 5 - t / 7 + add;
    };
    std::cout << get(b) - get(a - 1) << enld;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}