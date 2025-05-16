//  A. MEX Destruction
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
    std::vector<i32> v;
    for (i32 i = 0; i < n; i++) {
        i32 t;
        std::cin >> t;
        if (t == 0 && v.size() == 0) continue;
        v.push_back(t);
    }
    while (!v.empty() && v.back() == 0) v.pop_back();
    if (v.size() == 0) {
        std::cout << 0 << endl;
    } else {
        std::cout << 1 + (std::find(v.begin(), v.end(), 0) != v.end()) << endl;
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
