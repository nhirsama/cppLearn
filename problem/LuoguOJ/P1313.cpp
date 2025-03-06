//P1313 [NOIP 2011 提高组] 计算系数
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

ll qpow(ll a, ll b, ll p) {
    ll ans = 1;
    ll base = a;
    while (b) {
        if (b & 1) {
            ans *= base;
            ans %= p;
        }
        base *= base;
        base %= p;
        b >>= 1;
    }
    return ans;
}

ll C(ll a, ll b, ll p) {
    if (b > a)
        return 0;
    ll res = 1;
    for (ll i = 1, j = a; i <= b; i++, j--) {
        res = res * j % p;
        res = res * qpow(i, p - 2, p) % p;
    }
    return res;
}

ll lucas(ll m, ll n, ll p) {
    if (m == 0)return 1;
    return C(m % p, n % p, p) * lucas(m / p, n / p, p) % p;
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, k, m, n, p = 10007;
    cin >> a >> b >> k >> n >> m;
    ll ans = qpow(a, n % (p - 1), p) * qpow(b, m % (p - 1), p) % p;
    ans *= lucas(k, k - n, p);
    cout << ans % p << endl;
    return 0;
}
