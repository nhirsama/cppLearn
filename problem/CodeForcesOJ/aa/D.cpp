#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
int gety(int o, int r, int x) {
    int xx = o + x;
    return (int) sqrt(r * r - (xx - o) * (xx - o));
}

void Solve() {
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    vector<pii> x(n + 1);
    for (int i = 1; i <= n; i++)cin >> x[i].x;
    for (int i = 1; i <= n; i++)cin >> x[i].y;
    sort(x.begin() + 1,x.end());
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        for (int j = -x[i].y; j <= x[i].y; j++) {
            int v = gety(x[i].x,x[i].y, j);
            if (mp.count(j + x[i].x)) {
                mp[j + x[i].x] = max(mp[j + x[i].x], v);
            } else mp[j + x[i].x] = v;
        }
    }
    for (auto t: mp) {
        ans += t.y * 2 + 1;
    }
    cout << ans << endl;
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
