#define LOCAL
//P2330 [SCOI2005] 繁忙的都市
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
struct edge{
    int u, v, w;
    bool operator<(const edge& e) const {
        return w < e.w;
    }
}g[N];
int n,m,p[N];
int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &g[i].u, &g[i].v, &g[i].w);
    }
    sort(g,g+m);
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }
    int ans = 0,cnt = 0,max = 0;
    for (int i = 0; i < m; i++) {
        int u = g[i].u, v = g[i].v, w = g[i].w;
        u = find(u), v = find(v);
        if (u!=v) {
            p[u] = v;
            ans ++;
            max = w;
            cnt ++;
        }
        if (cnt == n-1) break;
    }
    cout << ans <<' '<<max<< endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}