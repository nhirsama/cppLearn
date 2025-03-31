#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const ll mod = 1000000007;

ll binpow (ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res *= a; res %= mod;
        }
        a *= a; a %= mod; n >>= 1;
    }
    return res;
}

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    int good = 0, sum = 0;
    for (int i = 0; i < k; ++i) {
        int x, y, c; cin >> x >> y >> c;
        if ((x == 1 && y == 1) || (x == 1 && y == m) || (x == n && y == 1) || (x == n && y == m)) continue;
        if (x == 1 || y == 1 || x == n || y == m) {
            ++good; sum += c;
        }
    }
    if (good == 2 * (n + m - 4)) {
        cout << (sum % 2 ? 0 : binpow(2, n * m - k)) << '\n';
    } else {
        cout << binpow(2, n * m - k - 1) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
