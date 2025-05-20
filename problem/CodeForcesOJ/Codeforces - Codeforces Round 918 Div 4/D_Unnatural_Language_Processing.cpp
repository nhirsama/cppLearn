//  D. Unnatural Language Processing
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
    std::string s;
    std::cin >> s;
    std::string ans;
    s += "____";
    bool flag = false;
    for (i32 i = 0; i < n; i++) {
        if (s[i] == 'b' || s[i] == 'c' || s[i] == 'd') ans.push_back(s[i]);
        if (flag) ans.push_back('.'), flag = false;
        if (s[i] == 'a' || s[i] == 'e') {
            ans.push_back(s[i]);
            if (s[i + 2] == 'a' || s[i + 2] == 'e') {
                ans.push_back('.');
            } else flag = true;
        }
    }
    if (ans.back() == '.') ans.pop_back();
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
