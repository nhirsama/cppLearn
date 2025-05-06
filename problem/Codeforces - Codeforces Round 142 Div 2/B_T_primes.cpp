//  B. T-primes

#include<bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
using pii = std::pair<i32, i32>;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
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
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

void nhir() {
    i64 n;
    std::cin >> n;
    i32 sn = std::sqrt(n);
    std::cout<<(sn*sn == n && isprime(sn) ? "YES\n" : "NO\n");
    // for (auto i: primes) {
    //     if (i*i > n) {
    //         std::cout << "NO\n";
    //         return;
    //     }
    //     if (n % i == 0) {
    //         if (n / i == i) {
    //             std::cout << "YES\n";
    //             return;
    //         } else {
    //             std::cout << "NO\n";
    //             return;
    //         }
    //     }
    // }
}

signed main() {
    IOS;
    sieve(1e6 + 1);
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
