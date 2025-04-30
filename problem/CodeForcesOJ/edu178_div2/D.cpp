//D
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
std::vector<int> minp, primes;
int P;

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

void nhir(std::vector<i64> &ps) {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (auto &i: a) {
        std::cin >> i;
    }
    std::sort(a.begin(), a.end(), std::greater<i64>());
    std::vector<i64> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    int l = 0, r = std::min(n, P);
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (sum[mid] >= ps[mid]) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << (n - l) << endl;
}

signed main() {
    IOS;
    sieve(6500000);
    P = primes.size();
    std::vector<i64> ps(P + 1, 0);
    for (int i = 1; i <= P; i++) {
        ps[i] = ps[i - 1] + primes[i - 1];
    }
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir(ps);
    return 0;
}
