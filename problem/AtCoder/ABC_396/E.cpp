//E - Min of Restricted Sum
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
using i64 = long long;
using i32 = int;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '


signed main() {
    IOS
    i64 n, m;
    cin >> n >> m;
    vector g(n + 1, vector<pll>());
    vector<i64> ans(n + 1);
    for (i32 i = 1; i <= m; i++) {
        i64 x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    vector<bool> st(n + 1);
    bool flag = true;
    vector<i64> val(n + 1);
    for (int i = 1; i <= n; i++) {
        if (st[i]) continue;
        if (!flag) break;
        vector<i64> a;
        a.push_back(i);
        val[i] = 0;
        auto dfs = [&](auto self, i32 u) -> void {
            st[u] = true;
            for (auto i: g[u]) {
                if (st[i.x]) {
                    if ((val[i.x] ^ val[u]) != i.y) {
                        flag = false;
                    }
                    continue;
                }
                a.push_back(i.x);
                val[i.x] = val[u] ^ i.y;
                self(self, i.x);
            }
        };
        dfs(dfs, i);
        for (int j = 0; j < 30; j++) {
            i64 cnt = 0;
            for (auto k: a) {
                if ((val[k] >> j) & 1) cnt++;
            }
            if (cnt < a.size() - cnt) {
                for (auto k: a) {
                    if ((val[k] >> j) & 1)
                        ans[k] = (ans[k] | 1ll << j);
                }
            } else {
                for (auto k: a) {
                    if (!((val[k] >> j) & 1))
                        ans[k] = (ans[k] | 1ll << j);
                }
            }
        }
    }
    if (flag) {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
    } else cout << -1 << endl;
    return 0;
}
