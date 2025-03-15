//P5651 基础最短路练习题
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
#define allp1(x) (x).begin() + 1, (x).end()
typedef pair<int, int> pii;

signed main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    IOS
    cin.tie(nullptr);
    ll n, m, q;
    cin >> n >> m >> q;
    vector g(n + 1, vector<pii>());
    for (int i = 1; i <= m; i++) {
        int x,y, v;
        cin >> x >> y >> v;
        g[x].push_back({y, v});
        g[y].push_back({x, v});
    }
    vector<int> dist(n + 1, (1ll << 31) - 1), st(n + 1);
    auto dijkstra = [&]() {
        priority_queue<pii, vector<pii>, greater<> > p;
        p.push({0, 1});
        st[1] = 1;
        dist[1] = 0;
        while (!p.empty()) {
            auto q = p.top();
            st[q.y] = 0;
            p.pop();
            for (auto [x,y]: g[q.y]) {
                if (dist[x] > (dist[q.y] ^ y)) {
                    dist[x] = (dist[q.y] ^ y);
                    if (!st[x]) {
                        st[x] = 1;
                        p.push({dist[x],x});
                    }
                }
            }
        }
    };
    dijkstra();
    while (q--) {
        int x,y;
        cin >> x >> y;
        cout << (dist[x] ^ dist[y]) << endl;
    }
    return 0;
}
