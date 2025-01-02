#define LOCAL
//P1119 灾后重建
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int g[N][N],n,m,t[N];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    memset(g, 0x3f, sizeof g);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=c;
        g[b][a]=c;
    }
    for(int i=0;i<n;i++) g[i][i] = 0;
    int q;
    cin>>q;
    int a,b,c;
    cin>>a>>b>>c;
    for(int k=0;k<n;k++){
        while(q && c<t[k]){
            if (t[a] > c || t[b] > c) cout << -1 << endl;
            else if(g[a][b] == 0x3f3f3f3f) cout<<-1<<endl;
            else cout<<g[a][b]<<endl;
            cin>>a>>b>>c;
            q--;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (g[i][j]>g[i][k]+g[k][j]) {
                    g[i][j] = g[i][k]+g[k][j];
                    g[j][i] = g[i][j];
                }
            }
        }
    }
    while(q){
        if(g[a][b] == 0x3f3f3f3f) cout<<-1<<endl;
        else cout<<g[a][b]<<endl;
        cin>>a>>b>>c;
        q--;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}