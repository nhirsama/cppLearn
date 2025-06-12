#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int inf = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int g = 0;
    for (int i = 0; i < n; i++) {
        g = gcd(g, a[i]);
    }

    int cnt = 0;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i] / g;
        if (b[i] == 1) {
            cnt++;
        }
    }

    if (cnt) {
        cout << n - cnt << '\n';
        return;
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int maxv = b.back();

    vector<int> dis(maxv + 1, inf);
    dis[1] = 0;
    for (int d = 2; d <= maxv; d++) {
        for (int v : b) {
            int u = gcd(d, v);
            if (u < d) {
                dis[d] = min(dis[d], dis[u] + 1);
            }
        }
    }

    int ans = inf;
    for (auto x : b) {
        ans = min(ans, dis[x]);
    }

    cout << ans + n - 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
