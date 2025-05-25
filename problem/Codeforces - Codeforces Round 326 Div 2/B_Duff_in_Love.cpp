//  B. Duff in Love
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
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

void nhir() {
    i32 n;
    std::cin >> n;
    for (i32 i = 2; i * i <= n; i++) {
        while (n % (i * i) == 0) {
            n /= i;
        }
    }
    std::cout << n << endl;
//    sieve(4e6 + 10);
//    std::set<i32> s;
//    for (auto i: primes) {
//        while (n % i == 0) {
//            s.insert(i);
//            n /= i;
//        }
//    }
//    i32 ans = 1;
//    for (auto i: s) ans *= i;
//    std::cout << ans << endl;
//    i32 n;
//    std::cin >> n;
//    auto check = [&](i32 i) -> bool {
//        for (i32 j = 0; i != 1; j++) {
//            if (i % primes[j] == 0) {
//                i /= primes[j];
//                if (i % primes[j] == 0) {
//                    return false;
//                }
//            }
//        }
//        return true;
//    };
//    std::set<i32> ys;
//    ys.insert(1);
//    i32 nn = n;
//    for (i32 i = 1; i <= std::sqrt(n); i++) {
//        if (nn % i == 0) {
//            ys.insert(i);
//            ys.insert(nn / i);
//        }
//    }
//    i32 ans = 1;
//    for (auto i: ys) {
//        for (auto j: ys) {
//            if (check(i * j)) {
//                ans = std::max(ans, i * j);
//            }
//        }
//    }
//    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}