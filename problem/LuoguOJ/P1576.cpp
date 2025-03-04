//P1576 最小花费
#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
vector g(N + 1, vector<pair<int, int> >());
int n, m, A, B;
double dist[N];
bool st[N];

void spfa() {
    dist[B] = 100;
    queue<int> q;
    q.push(B);
    st[B] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (auto i: g[t]) {
            if (dist[i.first] < dist[t] - dist[t] * i.second / 100) {
                dist[i.first] = dist[t] - dist[t] * i.second / 100;
                if (st[i.first])continue;
                st[i.first] = true;
                q.push(i.first);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    cin >> A >> B;
    spfa();
    printf("%.8f", 100 / dist[A] * 100);
}
