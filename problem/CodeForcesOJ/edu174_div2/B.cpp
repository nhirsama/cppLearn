#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

void Func() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n + 3, vector<int>(m + 3));
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            mp[v[i][j]] = 1;
        }
    }
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == v[i + 1][j] || v[i][j] == v[i][j + 1]) {
                mp[v[i][j]] = 2;
                flag = 2;
            }
        }
    }
    ll ans = 0;
    for (auto i: mp) {
        ans += i.second;
    }
    cout << ans - flag endl;
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
