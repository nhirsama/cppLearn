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

void Solve() {
    ll n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        ll c = 0;
        for (int j = 0; j < m; j++) {
            c = c ^ (arr[i][j] - '0');
        }
        if (c) a++;
    }
    for (int i = 0;i<m;i++) {
        ll c = 0;
        for (int j = 0; j < n; j++) {
            c = c ^ (arr[j][i] - '0');
        }
        if (c) b++;
    }
    ll ans = 0;
    cout << max(a,b) << endl;
}

signed main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
