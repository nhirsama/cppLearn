#include <bits/stdc++.h>
using namespace std;
const int N = 2505;
int dits[N];
vector<pair<int, int> > g[N];
int dist[N], st[N];

int main() {
    int n, c, be, en;
    cin >> n >> c >> be >> en;
    for (int i = 1; i <= c; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        g[a].push_back({b, d});
        g[b].push_back({a, d});
    }
    auto dijkstra = [&]() {
        memset(dist, 0x3f, sizeof dist);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        q.emplace(0, be);
        dist[be] = 0;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int t = p.second;
            for (auto i: g[t]) {
                if (dist[i.first] > dist[t] + i.second) {
                    dist[i.first] = dist[t] + i.second;
                    q.push({dist[i.first], i.first});
                }
            }
        }
    };
    dijkstra();
    cout << dist[en];
}
