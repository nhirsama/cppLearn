//  C - Sum of Product
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 ans = 0, n;
    std::cin >> n;
    std::vector<i32> v(n + 1);
    for (i32 i = 1; i <= n; i++) {
        std::cin >> v[i];
        v[i] += v[i - 1];
    }
    // for (auto &i:v) std::cin>>i;
    for (i32 i = 1; i < n; i++) {
        ans += (v[i] - v[i - 1]) * (v[n] - v[i]);
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
