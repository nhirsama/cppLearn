//  G. Matching

#include<bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
using pii = std::pair<i32, i32>;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void nhir() {
    i32 n;
    std::cin >> n;
    std::map<i32, std::vector<i32> > mv;
    std::vector<i32> v(n + 1);
    for (i32 i = 1; i <= n; i++) {
        std::cin >> v[i];
        mv[v[i] - i].push_back(v[i]);
    }
    i32 ans = 0;
    for (auto &[x,y]: mv) {
        std::sort(all(y), std::greater<>());
        // for (auto i:y) {
        //     std::cout<<i<< ' ';
        // }
        // std::cout<<endl;
        if (y.size() >= 2) {
            for (i32 i = 0; i < y.size() - 1; i += 2)
                ans = std::max(ans, y[i] + y[i + 1] + ans);
        }
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
