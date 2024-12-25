#define LOCAL
//这题对于3371来说会TLE，所以bellmanford不行 ，得用堆优化的dijkstra
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5,M = 5e5+5;
struct node {
    int a,b,w;
} g[M];
int n,m,s,dist[N],backup[N];
int BellmanFord(){
    for(int i=0;i<=n;i++) {
        dist[i]=INT_MAX;
    }
    dist[s] = 0;
    for(int i = 1; i <= n;i++){
        memcpy(backup,dist,sizeof dist);
        for(int j = 1; j <= m; j++){
            struct node temp = g[j];
            dist[temp.b] = min(dist[temp.b]*1ll,dist[temp.a]*1ll+temp.w);
        }
    }
    if(dist[n] > 0x3f3f3f3f) return -1;
    return dist[n];
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    scanf("%d%d%d",&n,&m,&s);
    for(int i = 1; i <= m;i++){
        scanf("%d%d%d",&g[i].a,&g[i].b,&g[i].w);
    }
    BellmanFord();
    for(int i = 1; i <= n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}