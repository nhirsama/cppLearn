//  B - Not All
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector<bool> st(n + 1);
    i32 cnt = 0;
    st[0] = true;
    for (i32 i = 0; i < n; i++) {
        if (v[i] > m) continue;
        if (st[v[i]]) continue;
        if (cnt + 1 == m) {
            std::cout << n - i << endl;
            return;
        }
        st[v[i]] = true;
        cnt++;
    }
    std::cout << 0 << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
