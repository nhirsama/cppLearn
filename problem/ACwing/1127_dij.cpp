#include <bits/stdc++.h>
using namespace std;
const int N = 805;
int pn[N], dist[N], st[N];
vector<pair<int, int> > g[N];

int main() {
    int n, m, p;
    cin >> p >> n >> m;
    for (int i = 1; i <= p; i++) {
        int t;
        cin >> t;
        pn[t]++;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        g[a].push_back({b, d});
        g[b].push_back({a, d});
    }
    long long ans = 0x3f3f3f3f;
    auto dijkstra = [&](int u) {
        memset(dist, 0x3f, sizeof dist);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        q.emplace(0, u);
        dist[u] = 0;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int t = p.second;
            st[t] = false;
            for (auto i: g[t]) {
                if (dist[i.first] > dist[t] + i.second) {
                    dist[i.first] = dist[t] + i.second;
                    if (st[i.first])continue;
                    q.push({dist[i.first], i.first});
                    st[i.first] = true;
                }
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        long long dit = 0;
        for (int j = 1; j <= n; j++)dit += dist[j] * pn[j];
        ans = min(ans, dit);
    }
    cout << ans;
}
