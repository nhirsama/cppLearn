//  A. Min Max Swap
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
    std::vector<i32> a(n), b(n);
    for (auto &i: a) std::cin >> i;
    for (auto &i: b) std::cin >> i;
    for (i32 i = 0; i < n; i++) {
        if (a[i] < b[i]) std::swap(a[i], b[i]);
    }
    std::cout << *std::ranges::max_element(a) * *std::ranges::max_element(b) << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
