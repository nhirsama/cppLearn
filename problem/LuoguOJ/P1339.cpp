#define LOCAL
//P1339 [USACO09OCT] Heat Wave G
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 2550;
int g[N][N],b[N],n,m,s,t;
bool vi[N];
int Dijkstra(){
    memset(b,0x3f,sizeof b);
    b[t] = 0;
    for(int i=0;i<n;i++){
      int tt = -1;
        for(int j = 1;j<=n;j++){
            if(!vi[j] && (tt==-1 || b[j] < b[tt])) tt = j;
        }
        vi[tt] = true;
        for(int j = 1;j<=n;j++){
            b[j] = min(b[j],b[tt]+g[tt][j]);
        }
    }
    if(b[s]==0x3f3f3f3f) return -1;
    return b[s];
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m>>s>>t;
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(g[a][b]>c)g[a][b]=c;
        if(g[b][a]>c)g[b][a]=c;
    }
    int a = Dijkstra();
    cout<<a<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}