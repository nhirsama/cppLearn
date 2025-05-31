//  Two Coins
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n + 2);
    i32 k;
    std::cin >> k;
    for (auto i = 0; i < k; i++) {
        i32 l, r;
        std::cin >> l >> r;
        v[l]++;
        v[r + 1]--;
    }
    i32 ans = 0x3f3f3f3f3f;
    for (i32 i = 1; i <= n; i++) {
        v[i] += v[i - 1];
        ans = std::min(ans, v[i]);
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}