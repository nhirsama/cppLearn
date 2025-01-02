#define LOCAL
//P1359 租用游艇
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n,g[N][N],dist[N];
bool vis[N];
int Dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[1] = 0;
    for(int i = 1; i <= n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if((!vis[j]) && (dist[t] > dist[j] || t == -1)) t = j;
        }
        vis[t] = true;
        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j],dist[t]+g[t][j]);
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n;
    memset(g,0x3f,sizeof g );
    for (int i = 1; i <= n; i++) {
        g[i][i] = 0;
        for (int j = i+1 ;j <= n; j++) {
            cin >> g[i][j];
        }
    }
    int t = Dijkstra();
    cout << t << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}