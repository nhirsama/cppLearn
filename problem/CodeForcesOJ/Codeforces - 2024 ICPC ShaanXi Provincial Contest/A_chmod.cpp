//  A. chmod
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    std::string s, ans = "rwxrwxrwx";
    std::cin >> s;
    for (i32 i = 0; i < 3; i++) {
        i32 t = s[i] - '0';
        for (i32 j = 0; j < 3; j++) {
            if (!(t >> (2 - j) & 1)) ans[j + i * 3] = '-';
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
