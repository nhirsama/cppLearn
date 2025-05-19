//  G. Disappearing Number
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
    char n;
    std::cin>>s>>n;
    for (auto &c:s) if (c>n) c--;
    i32 ans = 0;
    for (auto c:s) {
        ans= ans*9+(c-'0');
    }
    std::cout<<++ans<<'\n';
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}