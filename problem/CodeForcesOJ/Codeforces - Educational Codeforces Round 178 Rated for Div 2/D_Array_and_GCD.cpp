//  D. Array and GCD

#include<bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
using pii = std::pair<i32, i32>;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
std::vector<i32> minp, primes;
std::vector<i32> prsum;

void sieve(i32 n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (i32 i = 2; i <= n; i++) {
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
    }
}

bool isprime(i32 n) {
    return minp[n] == n;
}

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n), pre(n + 1);
    i32 sum = 0;
    for (auto &i: v) std::cin >> i;
    std::ranges::sort(v, std::greater<i32>());
    for (i32 i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + v[i];
    }
    i32 l = 0, r = n;
    while (l < r) {
        i32 mid = (l + r + 1) >> 1;
        if (pre[mid] >= prsum[mid]) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << n - l << endl;
}

signed main() {
    IOS;
    sieve(1e7);
    prsum.push_back(0);
    for (auto i: primes) {
        prsum.push_back(prsum.back() + i);
    }
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
