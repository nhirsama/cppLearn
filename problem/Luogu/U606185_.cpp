//  U606185 质数筛太没意思了所以我们加入了合数筛
//  11:41
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 998244353;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};
std::vector<int> minp, primes, ffunc, pre;
int hs = 0;

void sieve(int n) {
    minp.assign(n + 1, 0);
    ffunc.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p: primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
        if (minp[i] != i) {
            ffunc[i] = ++hs;
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

void nhir() {
    int l, r;
    std::cin >> l >> r;
    std::cout << (pre[r] - pre[l - 1] + mod) % mod << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    sieve(5e6 + 10);
    pre.assign(5e6 + 10, 0);
    for (int i = 1; i <= 5e6; i++) {
        pre[i] = (pre[i - 1] + 1ll * ffunc[i] * i) % mod;
    }
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}
