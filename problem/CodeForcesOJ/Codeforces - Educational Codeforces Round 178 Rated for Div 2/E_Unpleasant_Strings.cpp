//  E. Unpleasant Strings
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using pic = std::pair<i32, char>;

void nhir() {
    i32 n, m;
    std::string s;
    std::cin >> n >> m >> s;
    std::vector dp(m, std::vector<i32>(n + 2, n + 1));
    for (i32 x = 0; x < m; x++) {
        for (i32 i = n - 1; ~i; i--) {
            dp[x][i] = s[i] == 'a' + x ? i + 1 : dp[x][i + 1];
        }
    }
    std::vector<i32> f(n + 2, 1e9);
    f[n + 1] = 0;
    for (i32 i = n; ~i; i--) {
        for (i32 x = 0; x < m; x++) {
            f[i] = std::min(f[i], 1 + f[dp[x][i]]);
        }
    }
    // std::vector<i32> cnt(m);
    // std::vector<i32> dp(n+1);
    // dp[n] = 1;
    // for (i32 i = n-1;~i;i--) {
    //     dp[i] = 1+*std::ranges::min_element(cnt);
    //     cnt[s[i]-'a']++;
    // }
    i32 q;
    std::cin >> q;
    while (q--) {
        std::string qs;
        std::cin >> s;
        i32 p = 0;
        for (auto c: s) {
            p = dp[c - 'a'][p];
        }
        std::cout << f[p] << endl;
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
