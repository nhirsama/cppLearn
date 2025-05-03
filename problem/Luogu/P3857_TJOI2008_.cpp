//  P3857 [TJOI2008] 彩灯
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

i32 power(i32 a, i64 b, i32 p) {
    i32 res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector<i32> v(m);
    for (i32 i = 0; i < m; i++) {
        std::string s;
        std::cin >> s;
        i32 res = 0;
        for (i32 j = 0; j < n; j++) {
            if (s[j] == 'O') res += 1ll << j;
        }
        v[i] = res;
    }
    i32 k = gauss(v);
    i32 ans = power(2, k, 2008);
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
