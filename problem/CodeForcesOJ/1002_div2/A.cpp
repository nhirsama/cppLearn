#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '
#define int long long
typedef pair<int, int> pii;

void Solve() {
    ll n;
    cin >> n;
    set<int> a, b;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        b.insert(x);
    }
    if (a.size() >= 3 || b.size() >= 3) {
        cout << "YES" << endl;
    } else if (a.size() + b.size() > 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
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
