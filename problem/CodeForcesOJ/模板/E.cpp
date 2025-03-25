//E
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long
vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        // primecnt.push_back(primecnt.back());
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            //primecnt.back()++;
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
    cin >> n;
    i64 ans = 0;
    auto t = upper_bound(primes.begin(), primes.end(), n);
    for (auto p = primes.begin(); p != t; ++p)
        ans += n / *p;
    cout << ans << endl;
    // ans+=primecnt[n];
    // for (int i = 0; primes[i] <= n; i++) {
    //     ans += (primecnt[n / primes[i]]);
    // }
    // cout << ans << endl;
}

signed main() {
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    IOS;
    sieve(1e7+10);
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
