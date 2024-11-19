#include<iostream>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
const int MAXN=2e3+5;
char a[MAXN][MAXN];
int n,m,r,c,x,y;
struct node{
    int x,y,r,s;//坐标,step->x-1
}dp,dq;
queue <node> us;
int xx[MAXN][MAXN];
int dx[4]={-1,0,0,1},dy[4]={0,1,-1,0},dr[4]={0,0,1,0},ds[4]={0,1,0,0};
int ans=0;
int main(){
    cin>>n>>m>>r>>c>>x>>y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            xx[i][j]=1e9;
        }
    dp.x=r,dp.y=c,dp.r=0,dp.s=0;
    us.push(dp);
    while(!us.empty()){
        dp=us.front();
        us.pop();
        if(xx[dp.x][dp.y]<=dp.r||dp.r>x||dp.s>y||a[dp.x][dp.y]!='.')
            continue;
        if(xx[dp.x][dp.y]==1e9)
            ans++;
        xx[dp.x][dp.y]=dp.r;
        for(int i=0;i<4;i++){
            dq.x=dp.x+dx[i];
            dq.y=dp.y+dy[i];
            dq.r=dp.r+dr[i];
            dq.s=dp.s+ds[i];
            us.push(dq);
        }
    }
    cout<<ans;
}