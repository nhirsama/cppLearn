#include <bits/stdc++.h>
using namespace std;
const int N = 2505;
int dits[N];
vector<pair<int, int> > g[N];
int dist[N], st[N];

int main() {
    int n, c, be, en;
    cin >> n >> c >> be >> en;
    int a, b, d, i = 1;
input_loop_start:
    if (i > c) goto input_loop_end;
    cin >> a >> b >> d;
    g[a].push_back({b, d});
    g[b].push_back({a, d});
    i++;
    goto input_loop_start;
input_loop_end:
    memset(dist, 0x3f, sizeof dist);
    vector<pair<int, int> > q;
    q.push_back({0, be});
    dist[be] = 0;

queue_loop_start:
    if (q.empty()) goto queue_loop_end;
    int min_val = 0x3f3f3f3f, min_idx = -1;
    for (int j = 0; j < q.size(); j++) {
        if (q[j].first < min_val) {
            min_val = q[j].first;
            min_idx = j;
        }
    }
    if (min_idx == -1) goto queue_loop_end;
    auto p = q[min_idx];
    q.erase(q.begin() + min_idx);

    int t = p.second;
    int edge_idx = 0;
dijkstra_loop_start:
    if (edge_idx >= g[t].size()) goto dijkstra_loop_end;
    auto inls = g[t][edge_idx];
    if (dist[inls.first] > dist[t] + inls.second) {
        dist[inls.first] = dist[t] + inls.second;
        q.push_back({dist[inls.first], inls.first});
    }
    edge_idx++;
    goto dijkstra_loop_start;
dijkstra_loop_end:

    goto queue_loop_start;
queue_loop_end:

    cout << dist[en];
    return 0;
}
