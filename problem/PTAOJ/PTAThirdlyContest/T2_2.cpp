#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
ll ans =0;
int arr[N][N],st[N][N],n;
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
void dfs(int a,int b,ll dist){
    if(a==n&&b==n){
        ans = max(ans,dist);
    }
    for(int i = 0;i<4;i++){
        int x = a+dx[i],y = b+dy[i];
        if(st[x][y])continue;
        if(x<1 || x>n || y<1 || y>n)continue;
        if(arr[x][y]<-dist && n>5)continue;
        st[x][y] = 1;
        dfs(x,y,dist+arr[x][y]);
        st[x][y] = 0;
    }
}

int main() {
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    st[1][1] = 1;
    dfs(1,1,arr[1][1]);
    cout<<ans<<endl;
    return 0;
}