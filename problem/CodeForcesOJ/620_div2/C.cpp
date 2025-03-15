#define LOCAL
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void Solve() {
    ll n, m;
    cin >> n >> m;
    ll t = 0, upper = m, lower = m;
    vector arr(n + 1, vector<ll>(4));
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for (int i = 1; i <= n; i++) {
        upper += arr[i][0] - t;
        lower -= arr[i][0] - t;
        t = arr[i][0];
        upper = min(upper, arr[i][2]);
        lower = max(lower, arr[i][1]);
        if (upper < lower) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
