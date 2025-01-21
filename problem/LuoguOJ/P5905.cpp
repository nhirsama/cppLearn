#define LOCAL
//P5905 【模板】全源最短路（Johnson）
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 3e3+10,M = 5e4+N;
int g[M][3],n,m;
int dist[N];
int bellman_ford(){

    memset(dist,0x3f,sizeof(dist));
    dist[0]=0;
    int cnt = 0;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<m+n;j++){
            if(dist[g[j][1]]>dist[g[j][0]]+g[j][2]){
                if(cnt>=n+1)return 1;
                dist[g[j][1]]=dist[g[j][0]]+g[j][2];
                cnt++;
            }
        }
    }
    for(int i=0;i<=m;i++){
        g[i][2] = g[i][2]+dist[g[i][0]]-dist[g[i][1]];
    }
    return 0;
}
int dijkstra(){
    priority_queue<int[3]>s;

}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
	cin>>n>>m;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d",&g[i][0],&g[i][1],&g[i][2]);
    }
    for (int i = 1; i < n; i++) {
      g[i+m][0] = i; g[i+m][1] = 0; g[i+m][2] = 0;
    }
    if(bellman_ford()) puts("-1");
    else {

    };

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}