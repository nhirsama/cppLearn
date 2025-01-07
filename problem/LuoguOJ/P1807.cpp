#define LOCAL
//P1807 最长路
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int M = 5e4+10;
int g[M][3],n,m,dist[1505];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d",&g[i][0],&g[i][1],&g[i][2]);
    }
    memset(dist,-0x3f,sizeof(dist));
    dist[1]=0;
    for (int i = 1;i<=n;i++) {
        for (int j = 0;j<m;j++) {
            if (dist[g[j][1]] < dist[g[j][0]]+g[j][2]) {
                dist[g[j][1]] = dist[g[j][0]]+g[j][2];
            }
        }
    }
    if (dist[n]<=dist[n+1]/2) {
        cout<< -1 <<endl;
    }
    else {
        cout<<dist[n]<<endl;
    }
        #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}