//  F. Greetings
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using pbds = __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<std::array<i32, 2> > v(n);
    for (i32 i = 0; i < n; i++) {
        std::cin >> v[i][0] >> v[i][1];
    }
    std::ranges::sort(v, [](auto a, auto b) { return a[1] < b[1]; });
    pbds st;
    i32 ans = 0;
    for (auto p: v) {
        ans += st.size() - st.order_of_key(p[0]);
        st.insert(p[0]);
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
