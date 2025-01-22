#define LOCAL
//P5905 【模板】全源最短路（Johnson）
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
vector<pair<int, int> > g[N];
int n, m, spfaDist[N], dijDist[N];

int spfa() {
    memset(spfaDist, 0x3f, sizeof(spfaDist));
    int inQueNum[N]{0};
    bool st[N]{0};
    queue<int> q;
    spfaDist[0] = 0;
    q.push(0);
    spfaDist[0]++;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        st[u] = false;
        for (auto v: g[u]) {
            if (spfaDist[v.first] > spfaDist[u] + v.second) {
                spfaDist[v.first] = spfaDist[u] + v.second;
                if (!st[v.first]) {
                    q.push(v.first);
                    st[v.first] = true;
                    inQueNum[v.first]++;
                }
            }
            if (inQueNum[v.first] >= n) {
                return 1;
            }
        }
    }
    return 0;
}

void dijkstra(int i) {
    bool st[N] = {0};
    memset(dijDist, 0x3f, sizeof(dijDist));
    dijDist[i] = 0;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, i));
    st[i] = true;
    while (!q.empty()) {
        auto u = q.top();
        q.pop();
        st[u.second] = false;
        for (auto v: g[u.second]) {
            if (dijDist[v.first] > dijDist[u.second] + v.second) {
                dijDist[v.first] = dijDist[u.second] + v.second;
                if (!st[v.first]) {
                    //q的first元素存储负权值，使大根堆变为小根堆
                    q.push(make_pair(-v.second, v.first));
                    st[v.first] = true;
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
    }
    for (int i = 1; i <= n; i++) {
        g[0].push_back(make_pair(i, 0));
    }
    if (spfa()) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (auto &v: g[i]) {
            v.second += spfaDist[i] - spfaDist[v.first];
        }
    }
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        long long ans = 0;
        for (int j = 1; j <= n; j++) {
            if (dijDist[j] > 0x3f3f3f3f / 2) {
                ans += 1e9 * j;
            }
            else ans += 1ll*(dijDist[j] - spfaDist[i] + spfaDist[j]) * j;
        }
        cout << ans << endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
