//  XOR
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

i32 gauss(std::vector<long long> &v) {
    i32 n = v.size();
    i32 k = 0;
    for (i32 i = 62; ~i; i--) {
        for (i32 j = k; j < n; j++) {
            if (v[j] >> i & 1) {
                std::swap(v[j], v[k]);
                break;
            }
        }
        if ((v[k] >> i & 1) == 0) continue;
        for (i32 j = 0; j < n; j++) {
            if (j != k && (v[j] >> i & 1)) v[j] ^= v[k];
        }
        k++;
        if (k == n) break;
    }
    return k;
}

i32 Case = 1;

void nhir() {
    std::cout << "Case #" << Case++ << ":\n";
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    i32 k = gauss(v);
    i32 q;
    std::cin >> q;
    while (q--) {
        i32 res = 0;
        i32 t;
        std::cin >> t;
        if (k < n) t--;
        if (t >= 1ll << k) {
            std::cout << -1 << endl;
        } else {
            for (i32 cnt = 0; t >> cnt; cnt++) {
                if (t >> cnt & 1)res ^= v[k - cnt - 1];
            }
            std::cout << res << endl;
        }
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
