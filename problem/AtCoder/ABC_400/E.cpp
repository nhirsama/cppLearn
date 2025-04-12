//E
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e6 + 10;
constexpr i64 M = 1e12;
constexpr int mod = 1e9 + 7;

std::vector<i64> primepow();

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
std::vector<int> minp, primes;
std::vector<i64> dp;

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
    auto p = std::lower_bound(all(dp), n);
    if (*p > n) p--;
    std::cout << *p << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    sieve(N);
    for (i32 i = 0; i < primes.size(); i++) {
        for (i32 j = i + 1; j < primes.size() && 1ll * primes[i] * primes[j] < N; j++) {
            i64 a = primes[i];
            for (; a < N; a *= primes[i]) {
                i64 b = primes[j];
                for (; a * b < N; b *= primes[j]) {
                    dp.push_back(a * b * a * b);
                }
            }
        }
    }
    std::sort(all(dp));
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }

    while (T--) nhir();
    return 0;
}
