//  C. Make It Beautiful
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    std::array<i32, 60> cnt{};
    i32 ans = 0;
    for (i32 i = 0; i < 60; i++) {
        for (auto j: v) {
            if ((j & 1ll << i)) cnt[i]++;
            else {
                if (k >= (1ll << i)) {
                    cnt[i]++;
                    k -= 1ll << i;
                }
            }
        }
        ans += cnt[i];
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
