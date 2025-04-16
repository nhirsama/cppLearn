//  G. Skibidus and Capping
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
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
    std::map<i32, i64> pr, spr;
    for (i32 i = 0; i < n; i++) {
        i64 m;
        std::cin >> m;
        if (isprime(m)) pr[m]++;
        else {
            for (auto pp: primes) {
                if (m % pp == 0) {
                    if (isprime(m / pp)) spr[m]++;
                    break;
                }
            }
        }
    }
    i64 pcnt = 0, ans = 0;
    for (auto [x,y]: pr) {
        pcnt += y;
    }
    for (auto [x,y]: pr) {
        ans += y * (pcnt - y);
    }
    ans /= 2;
    for (auto [x,y]: spr) {
        for (auto pp: primes) {
            if (x % pp == 0) {
                if (isprime(x / pp)) {
                    if (pp != x / pp) ans += y * pr[pp] + y * pr[x / pp];
                    else ans += y * pr[pp];
                }
                break;
            }
        }
        ans += y * (y + 1) / 2;
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    sieve(2e5 + 10);
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
