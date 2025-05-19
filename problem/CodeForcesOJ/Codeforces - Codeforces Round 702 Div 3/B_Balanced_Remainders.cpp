//  B. Balanced Remainders
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
    std::vector<i32> v(n);
    std::vector<i32> cnt(3);
    for (auto &i: v) std::cin >> i, cnt[i % 3]++;
    for (i32 i = 0; i < 3; i++) {
        cnt.push_back(cnt[i]);
    }
    i32 ans = 0;
    for (i32 i = 0; i < 3; i++) {
        if (cnt[i] > n / 3) {
            i32 t = (cnt[i] - n / 3);
            for (i32 j = 1; j < 3; j++) {
                if (cnt[i + j] < n / 3) {
                    i32 give = std::min(t, n / 3 - cnt[i + j]);
                    cnt[i + j] += give;
                    ans += give * j;
                    t -= give;
                }
            }
        }
    }
    //10 2 3
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
