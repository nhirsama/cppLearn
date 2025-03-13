//D. 算法竞赛新手
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
long long ans = (1ll << 62);

int main() {
    IOS
    int n, m,x;
    cin >> n >> m >> x;
    vector<vector<int> > arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int c;
        for (int j = 0; j <= m; j++) {
            cin >> c;
            arr[i].push_back(c);
        }
    }
    vector<ll> v(m + 1);
    vector<bool> st(n + 1);
    auto dfs = [&](auto self, ll q, int num)-> void {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            if (v[i] >= x)cnt++;
        }
        if (cnt >= m) {
            ans = min(ans, q);
        }
        for (int i = 1 + num; i <= n; i++) {
            if (st[i]) continue;
            st[i] = true;
            for (int j = 1; j <= m; j++) v[j] += arr[i][j];
            self(self, q + arr[i][0], num + 1);
            st[i] = false;
            for (int j = 1; j <= m; j++) v[j] -= arr[i][j];
        }
    };
    dfs(dfs, 0, 0);
    if (ans == (1ll << 62)) {
        cout << -1 << endl;
    } else cout << ans << endl;
    return 0;
}
