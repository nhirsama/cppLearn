//模板
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
using i64 = long long;
using i32 = int;
typedef pair<int, int> pii;
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '

struct node {
    i32 a, b, c, d;
};

void nhir() {
    i32 n, k;
    cin >> n >> k;
    vector v(k + 1, vector<node>());
    for (i32 i = 1; i <= n; i++) {
        i32 a, b, c, d, t;
        cin >> t >> a >> b >> c >> d;
        v[t].push_back({a, b, c, d});
    }
    vector<vector<node> > vv;
    for (i32 i = 1; i <= k; i++) {
        if (v[i].size()) vv.push_back(v[i]);
    }
    i64 ans = 0;
    auto dfs = [&](auto &self, i32 num, i32 a, i32 b, i32 c, i32 d)-> void {
        if (num == vv.size()) {
            ans = max(ans, 1ll * a * b * c * d);
            return;
        }
        for (auto [aa,bb,cc,dd]: vv[num]) {
            self(self, num + 1, aa + a, bb + b, cc + c, dd + d);
        }
    };
    dfs(dfs, 0, 100, 100, 100, 100);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)nhir();
    return 0;
}
