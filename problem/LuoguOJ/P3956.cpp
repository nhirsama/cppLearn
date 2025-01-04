#define LOCAL
//P3956 [NOIP2017 普及组] 棋盘
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1005,M = 105;
int m,n,g[M][M],dx[] = {-1,1,0,0},dy[] = {0,0,-1,1},minMoney = 0x3f3f3f3f,money[M][M];
bool visited[M][M];
void dfs(int x,int y,int nowMoney,int mahon){
    if(x==m && y == m){
        minMoney = min(minMoney,nowMoney);
        return;
    }
    if(nowMoney >= minMoney){
        return;
    }
    if (nowMoney >= money[x][y]) {
        return;
    }
    for(int i=0;i<4;i++){
        int ix = x + dx[i],iy = y + dy[i];
        if(visited[ix][iy]) continue;
        if(ix<1 || ix>m || iy<1 || iy>m) continue;
        visited[ix][iy] = true;
        if(g[ix][iy] == -1 && mahon == -1) dfs(ix,iy,nowMoney+2,g[x][y]);
        else if(g[ix][iy] == -1 && mahon != -1) {}
        else if (mahon + g[ix][iy] == 1) dfs(ix,iy,nowMoney+1,-1);
        else if (mahon == g[ix][iy]) dfs(ix,iy,nowMoney,-1);
        else if(g[ix][iy]+g[x][y] == 1) dfs(ix,iy,nowMoney+1,-1);
        else if(g[ix][iy] == g[x][y]) dfs(ix,iy,nowMoney,-1);
        visited[ix][iy] = false;
    }
    money[x][y] = nowMoney;
}
int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P3956_3.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>m>>n;
    memset(g,-1,sizeof(g));
    memset(money,0x3f,sizeof(money));
    for (int i = 0; i < n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=c;
    }
    dfs(1,1,0,-1);
    if (minMoney == 0x3f3f3f3f) cout<<-1<<endl;
    else cout<<minMoney<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}