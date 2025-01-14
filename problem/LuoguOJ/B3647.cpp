#define LOCAL
//B3647 【模板】Floyd
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int g[N][N],n,m;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    memset(g,0x3f,sizeof(g));
    cin>>n>>m;
    for(int i=1;i<=n;i++) g[i][i] = 0;
    for(int i=0;i<m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        g[b][a]=g[a][b]=min(g[a][b],w);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(g[j][k] > g[j][i]+g[i][k]){
                    g[j][k] = g[j][i]+g[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}