//  A. Cards Partition
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;

    // i32 max = *std::max_element(v.begin(), v.end());
    // i32 cnt = 0;
    // for (auto i: v) if (i) k -= max - i, cnt++;
    // if (k<0) std::cout<<
    // std::cout << max + k / n << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
