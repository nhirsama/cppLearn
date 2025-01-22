#define LOCAL
//P5905 【模板】全源最短路（Johnson）
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10, M = 5e4 + N;
int n, m;
bool st[N];
int dist[N], cnt[N], dis[N];
vector<pair<int, int> > g[N];

struct edge {
    int u, v, w;
} edge[N];

int bellman_ford_t() {
    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    cnt[0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            bool flag = true;
            for (auto e: g[j]) {
                if (dist[e.first] > dist[j] + e.second) {
                    dist[e.first] = dist[j] + e.second;
                    flag = false;
                }
            }
            if (!flag) {
                cnt[j]++;
            }
            if (cnt[j] >= n) {
                return 1;
            }
        }
    }
    //    for(int i=0;i<=n;i++){
    //        for(int j=0;j<m+n;j++){
    //          if(dist[edge[j].u]>dist[edge[j].v]+edge[j].w){
    //            dist[edge[j].u] = dist[edge[j].v]+edge[j].w;
    //            cnt[edge[j].u]++;
    //            if(cnt[edge[j].u]==n){
    //              return 1;
    //            }
    //          }
    //        }
    //    }
    return 0;
}

//int bellman_ford(){
//    memset(dist,0x3f,sizeof(dist));
//    dist[0]=0;
//    int cnt = 0;
//    for(int i=0;i<=n+1;i++){
//        for(int j=0;j<m+n;j++){
//            if(dist[g[j][1]]>dist[g[j][0]]+g[j][2]){
//                if(cnt>=n+1)return 1;
//                dist[g[j][1]]=dist[g[j][0]]+g[j][2];
//                cnt++;
//            }
//        }
//    }
//    for(int i=0;i<=m;i++){
//        g[i][2] = g[i][2]+dist[g[i][0]]-dist[g[i][1]];
//    }
//    return 0;
//}
void dijkstra(int be) {
    priority_queue<pair<int, int> > s;
    memset(dis, 0x3f, sizeof dis);
    memset(st, 0, sizeof st);
    dis[be] = 0;
    s.push(make_pair(0, be));
    while (!s.empty()) {
        pair<int, int> p = s.top();
        s.pop();
        st[p.second] = false;
        p.first = -p.first;
        for (auto e: g[p.second]) {
            if (dis[e.first] > dis[p.second] + p.first) {
                dis[e.first] = dis[p.second] + p.first;
                if (!st[e.first]) {
                    st[e.first] = true;
                    s.push(make_pair(-dis[e.first], e.first));
                }
            }
            //dis[p.second] = min(dis[e.first] + p.first, dis[p.second]);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m;
    //读入点数与边数
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
        //scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    for (int i = 1; i <= n; i++) {
        //g[i].push_back(make_pair(0, 0));
        g[0].push_back(make_pair(i, 0));
        //      edge[i+m].u = i-1;
        //      edge[i+m].v = 0;
        //      edge[i+m].w = 0;
        //g[i+m][0] = i; g[i+m][1] = 0; g[i+m][2] = 0;
    }
    if (bellman_ford_t()) puts("-1");
    else {
        for (int i = 1; i <= n; i++) {
            for (auto &j:g[i]) {
                j.second += dist[i]-dist[j.first];
            }
        }
        for (int i = 1; i <= n; i++) {
            dijkstra(i);
            long long int ans = 0;
            for (int j = 1; j <= n; j++) {
                if (dis[j] > 0x3f3f3f3f / 2) ans += 1e9 * j;
                else ans += (dis[j]-dist[j]+dist[i]) * j;
            }
            cout << ans << endl;
        }
    };

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
