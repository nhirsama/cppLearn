#include <bits/stdc++.h>
using namespace std;
constexpr int N = 4e5 + 10;
typedef long long int ll;
#define int long long
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
long long dist[N];
bool st[N];
int n = 0;

void dijkstra(vector<vector<pair<int, int> > > g, int u,int x) // 求1号点到n号点的最短路距离
{
    dist[u] = x;
    priority_queue<pii, vector<pii>, greater<pii> > heap;
    heap.push({0, u});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (auto i: g[ver]) {
            int j = i.x;
            if (dist[j] > dist[ver] + i.y) {
                dist[j] = dist[ver] + i.y;
                heap.push({dist[j], j});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,x;
    cin >> n >> m >> x;
    vector<vector<pair<int, int> > > g(N);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(make_pair(v, 1));
        g[v + n].push_back(make_pair(u + n, 1));
    }
    for (int i = 1; i <= n; i++) {
        g[i].push_back(make_pair(i+n,x));
        g[i+n].push_back(make_pair(i,x));
    }
    memset(dist, 0x3f, sizeof dist);
    dijkstra(g, 1,0);
    long long ans = 0;
    ans = min(dist[n],dist[n*2]);
    cout << ans;
    return 0;
}
