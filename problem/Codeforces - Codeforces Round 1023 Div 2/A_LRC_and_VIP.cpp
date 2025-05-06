//  A. LRC and VIP

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
    std::vector<i32> v(n);
    std::vector<i32> ans(n, 1);
    for (auto &i: v) std::cin >> i;
    if (*std::max_element(v.begin(), v.end()) == *std::min_element(v.begin(), v.end())) {
        std::cout << "NO\n";
        return;
    }
    for (i32 i = 0; i < n; i++) {
        i32 gcd = 0;
        for (i32 j = 0; j < n; j++) {
            if (j == i) continue;
            gcd = (gcd == 0 ? v[j] : std::gcd(gcd, v[j]));
        }
        if (gcd != v[i]) {
            ans[i] = 2;
            std::cout << "YES\n";
            for (i32 j = 0; j < n; j++) {
                std::cout << ans[j] << (j + 1 < n ? ' ' : '\n');
            }
            return;
        }
    }
    std::cout << "NO\n";
    // if (std::ranges::find(v,1) != v.end() && std::ranges::find(v,2) != v.end()) {
    //
    // }
    // else
    //std::sort(v.begin(), v.end());
    // std::vector<i32> ans(n);
    // //ans[0] = 1;
    // i32 cnt = 0;
    // for (i32 i = 0; i < n; i++) {
    //     if (v[i] % 2 == 0) ans[i] = 1, cnt++;
    //     else ans[i] = 2;
    //     //std::cout<<v[i]<< ' ';
    // }
    // if (cnt == n || cnt == 0) {
    //     std::cout << "NO\n";
    //     return;
    // } else {
    //     std::cout << "YES\n";
    //     for (auto i: ans) {
    //         std::cout << i << ' ';
    //     }
    //     std::cout << endl;
    // }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
