//  B. Road Construction
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
    std::vector<bool> st(n + 1);
    for (i32 i = 1; i <= m; i++) {
        i32 a, b;
        std::cin >> a >> b;
        st[a] = st[b] = true;
    }
    auto p = std::find(st.begin() + 1, st.end(), false) - st.begin();
    std::cout << n - 1 << endl;
    for (i32 i = 1; i <= n; i++) {
        if (i == p) continue;
        std::cout << i << ' ' << p << '\n';
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
