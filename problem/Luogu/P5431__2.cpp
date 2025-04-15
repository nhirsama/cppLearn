//  P5431 【模板】模意义下的乘法逆元 2
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

i64 pow(i64 a, int b, int m) {
    // 复杂度是 log N
    i64 r = 1 % m; /**! 这里的取模容易遗漏 */
    for (; b; b >>= 1, a = a * a % m) {
        if (b & 1) r = r * a % m;
    }
    return r;
}
i64 read() {
    i64 ans = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9') c = std::cin.get();
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = std::cin.get();
    return ans;
}
void nhir() {
    i64 n, p, k, ai;
    n = read();
    p = read();
    k = read();
    i64 fm = 1, fz = k, kp = k;
    fm = read();
    for (i32 i = 2; i <= n; i++) {
        ai = read();
        kp = kp * k % p;
        fz = (ai * fz + fm * kp) % p;
        fm = fm * ai % p;
    }
    std::cout << fz * pow(fm, p - 2, p) % p << std::endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
