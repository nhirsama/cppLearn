//  P5431 【模板】模意义下的乘法逆元 2
//常数优化版本
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using u64 = uint64_t;
using u128 = __uint128_t;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

struct Montgomery {
    u64 m, m2, im, l1, l2;

    Montgomery() {
    }

    Montgomery(u64 m) : m(m) {
        l1 = -(u64) m % m, l2 = -(u128) m % m;
        m2 = m << 1, im = m;
        for (int i = 0; i < 5; i++) im *= 2 - m * im;
    }

    inline u64 operator()(i64 a, i64 b) const {
        u128 c = (u128) a * b;
        return u64(c >> 64) + m - u64((u64) c * im * (u128) m >> 64);
    }

    inline u64 reduce(u64 a) const {
        a = m - u64(a * im * (u128) m >> 64);
        return a >= m ? a - m : a;
    }

    inline u64 trans(i64 a) const {
        return (*this)(a, l2);
    }
};

i64 read() {
    i64 ans = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9') c = std::cin.get();
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = std::cin.get();
    return ans;
}

void nhir() {
    i64 n = read();
    i64 p = read();
    i64 k = read();
    Montgomery mont(p);
    u64 one = mont.trans(1);
    u64 uk = mont.trans(k);

    i64 ai = read();
    u64 fm = mont.trans(ai);
    u64 fz = uk;
    u64 kp = uk;

    for (i32 i = 2; i <= n; i++) {
        ai = read();
        u64 a = mont.trans(ai);
        kp = mont(kp, uk);
        u64 term1 = mont(a, fz);
        u64 term2 = mont(fm, kp);
        u64 sum = term1 + term2;
        if (sum >= p) sum -= p;
        fz = sum;
        // fm = fm * a
        fm = mont(fm, a);
    }

    auto mpow = [&](u64 a, i64 n) -> u64 {
        u64 r = one;
        while (n) {
            if (n & 1) r = mont(r, a);
            a = mont(a, a);
            n >>= 1;
        }
        return r;
    };
    u64 inv_fm = mpow(fm, p - 2);
    u64 res_mont = mont(fz, inv_fm);
    u64 res = mont(res_mont, 1);
    std::cout << res << std::endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
