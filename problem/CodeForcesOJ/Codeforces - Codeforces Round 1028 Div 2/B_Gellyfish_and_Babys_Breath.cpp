//  B. Gellyfish and Baby's Breath
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 998244353;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> p(n), q(n);
    for (auto &i: p) std::cin >> i;
    for (auto &i: q) std::cin >> i;
    std::vector<i32> maxp(n), maxq(n);
    for (i32 i = 0; i < n; i++) {
        maxp[i] = p[maxp[i ? maxp[i - 1] : 0]] > p[i] ? maxp[i ? maxp[i - 1] : 0] : i;
        maxq[i] = q[maxq[i ? maxq[i - 1] : 0]] > q[i] ? maxq[i ? maxq[i - 1] : 0] : i;
    }
    auto getmax = [&](i32 j)-> i32 {
        i32 a = maxp[j], b = j - a, c = maxq[j], d = j - c;
        if (std::max(p[a], q[b]) > std::max(q[c], p[d])) {
            return (1ll * power(2, p[a], mod) + power(2, q[b], mod)) % mod;
        }
        if (std::max(p[a], q[b]) == std::max(q[c], p[d]) && std::min(p[a], q[b]) > std::min(q[c], p[d])) {
            return (1ll * power(2, p[a], mod) + power(2, q[b], mod)) % mod;
        }
        return (1ll * power(2, p[d], mod) + power(2, q[c], mod)) % mod;
    };
    for (i32 i = 0; i < n; i++) {
        std::cout << getmax(i) << ' ';
    }
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
