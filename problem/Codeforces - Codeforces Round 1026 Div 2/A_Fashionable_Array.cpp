//  A. Fashionable Array
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    std::ranges::sort(v);
    i32 cnt = 1;
    for (i32 l = 0; l < n; l++) {
        for (i32 r = l; r < n; r++) {
            if ((v[l] & 1) == (v[r] & 1)) {
                cnt = std::max(cnt, r - l + 1);
            }
        }
    }
    std::cout << (n - cnt) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
