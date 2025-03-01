#include <bits/stdc++.h>
using namespace std;
constexpr int N = 4e5 + 10;
typedef long long int ll;
#define int long long
typedef pair<int, int> pii;
ll dist[N];
bool st[N];
int n;

void dijkstra(vector<vector<pii>> &g, int start) {
    memset(dist, 0x3f, sizeof(dist));
    memset(st, 0, sizeof(st));
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, start});

    while (!heap.empty()) {
        auto [d, u] = heap.top();
        heap.pop();

        if (st[u]) continue;
        st[u] = true;

        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                heap.push({dist[v], v});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, x;
    cin >> n >> m >> x;
    vector<vector<pii>> g(2 * n + 10);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // Original state edges: u -> v
        g[u].emplace_back(v, 1);
        // Reversed state edges: v -> u (represented as u+n <- v+n)
        g[v + n].emplace_back(u + n, 1);
    }

    // Add flip transitions for each node
    for (int u = 1; u <= n; ++u) {
        // Flip from original to reversed state
        g[u].emplace_back(u + n, x);
        // Flip back from reversed to original state
        g[u + n].emplace_back(u, x);
    }

    dijkstra(g, 1);
    ll ans = min(dist[n], dist[2 * n]);
    cout << ans << '\n';

    return 0;
}