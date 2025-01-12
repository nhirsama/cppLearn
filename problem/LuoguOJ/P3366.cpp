#define LOCAL
//P3366 【模板】最小生成树
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int g[N][N],dist[N],n,m;
bool visited[N];
int prim(){
    int res=0;
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<N;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if((!visited[j])&&(t == -1 || dist[j] < dist[t])) t = j;
        }
        visited[t]=true;
        if(dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
        res+=dist[t];
        for(int j=1;j<=n;j++){
            dist[j] = min(dist[j],g[t][j]);
        }
    }
    return res;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m;
    memset(g,0x3f,sizeof(g));
    for (int i = 0; i < m; i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        g[x][y] = g[y][x] =min(g[x][y],z);
    }
    int t = prim();
    if (t == 0x3f3f3f3f){
        puts("orz");
        return 0;
    }
    cout << t << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}