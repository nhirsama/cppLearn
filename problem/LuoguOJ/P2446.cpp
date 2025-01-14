#define LOCAL
//P2446 [SDOI2010] 大陆争霸
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
constexpr int M = 7e4 + 10, N = 3e3 + 10;
vector<pair<long long, long long> > g[N];
//struct edge{
//    int u,v,w;
//}g[M];
//存储该城市的结界发生器对应的结界城市位置
vector<long long> g2[N];
long long dist[N], n, m, jjf[N], ph[N];
bool vi[N];

long long dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!vi[j] && !jjf[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        vi[t] = true;
        for (auto j: g[t]) {
            long long v = j.first, w = j.second;
            dist[v] = min(dist[v], dist[t] + w);
        }
        for (auto j: g2[t]) {
            jjf[j]--;
            if (jjf[j] == 0) {
                dist[j] = max(dist[j], dist[t]);
            }
        }
    }
    // int ans = 0;
    // for(int i=1;i<=n;i++) {
    //     ans = max(ans,dist[i]);
    // }
    return dist[n];
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        long long u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        g[u].emplace_back(v, w);
        //        g[i] = {u,v,w};
    }
    for (int i = 1; i <= n; i++) {
        long long l;
        scanf("%lld", &l);
        jjf[i] = l;
        for (int j = 0; j < l; j++) {
            long long a;
            scanf("%lld", &a);
            g2[a].push_back(i);
        }
    }
    long long t = dijkstra();
    cout << t << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
