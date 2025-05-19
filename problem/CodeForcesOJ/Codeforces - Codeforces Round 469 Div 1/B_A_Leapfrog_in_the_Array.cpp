//  B. A Leapfrog in the Array
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

i32 n;

void nhir() {
    i32 t;
    std::cin >> t;
    if (t & 1) {
        std::cout << (t + 1) / 2 << endl;
    } else {
        while (!(t & 1)) {
            t += n - t / 2;
        }
        std::cout << (t + 1) / 2 << endl;
    }
}

signed main() {
    IOS;
    std::cin >> n;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
