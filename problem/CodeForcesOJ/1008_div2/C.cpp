#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

void Solve() {
    ll n;
    cin >> n;
    vector<ll> v(n * 2 + 10);
    for (ll i = 1; i <= n * 2; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end(), greater<ll>());
    ll a2 = v[1];
    for (int i = 2; i <= n * 2; i++) {
        if (i & 1) a2 -= v[i];
        else a2 += v[i];
    }
    cout << v[1] << ' ' << a2 << ' ';
    for (ll i = 2; i <= n * 2; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
