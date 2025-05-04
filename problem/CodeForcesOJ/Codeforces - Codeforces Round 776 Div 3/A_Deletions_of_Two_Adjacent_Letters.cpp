//  A. Deletions of Two Adjacent Letters
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    std::string s;
    char c;
    std::cin >> s >> c;
    for (i32 i = 0; i < s.size(); i++) {
        if (((i + 1) & 1) && s[i] == c) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
