#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void Solve() {
    ll n, k;
    cin >> n >> k;
    vector<pll> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].x;
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].y;
    }
    vector<pair<int, int> > ev;
    for (int i = 1; i <= n; ++i) {
        ev.emplace_back(arr[i].x, 1);
        ev.emplace_back(arr[i].y, 2);
    }
    sort(ev.begin(), ev.end());
    ll ans = 0;
    int cnt = n, bad = 0;
    for (int i = 0; i < ev.size();) {
        int x = ev[i].x;
        if (bad <= k) ans = max(ans, 1ll * x * cnt);
        while (i < ev.size() && ev[i].x == x) {
            bad += (ev[i].y == 1);
            bad -= (ev[i].y == 2);
            cnt -= (ev[i].y == 2);
            i++;
        }
    }
    cout << ans << endl;
}

int main() {
    IOS
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
