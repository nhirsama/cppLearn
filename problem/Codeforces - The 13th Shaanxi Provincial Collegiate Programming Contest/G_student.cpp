//  G. student
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
    for (auto &i: v) std::cin >> i;
    if (n <= 2) {
        std::cout << n << endl;
        return;
    }
    i32 max = *std::max_element(v.begin() + 1, v.begin() + n - 1);
    i32 min = *std::min_element(v.begin() + 1, v.begin() + n - 1);
    std::cout << 2 + (v[0] < max && v[n - 1] < max) + (v[0] > min && v[n - 1] > min) << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
