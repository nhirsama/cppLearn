//  B. Code For 1
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
i32 log2(i32 n) {
    i32 cnt = 0;
    while (n>>cnt)cnt++;
    return cnt;
}
i32 dfs(i32 n,i32 l,i32 r) {
    if (r<l) return 0;
    l = std::max(0ll,l);
    i32 v = 1ll<<log2(n);
    if (l>v) return 0;
    if (r<v) return 0;
    if (l == r) return n&1;
    return dfs(n>>1,)
}

void nhir() {
    i32 n,l,r;
    std::cin>>n>>l>>r;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}