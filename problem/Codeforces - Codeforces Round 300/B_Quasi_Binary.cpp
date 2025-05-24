//  B. Quasi Binary
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    std::string s;
    std::cin >> s;
    i32 ans = 0;
    for (auto i: s) {
        ans = std::max(ans, (i - '0') * 1ll);
    }
    std::vector<std::string> v(ans);
    for (auto i: s) {
        i32 cnt = i - '0';
        for (i32 j = 0; j < ans; j++) {
            v[j].push_back(j < cnt ? '1' : '0');
        }
    }
    std::cout << ans << endl;
    for (auto &i: v) {
        while (i.size() > 1 && i[0] == '0') i = i.substr(1);
        std::cout << i << ' ';
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}