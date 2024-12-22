#define LOCAL
//B3643 图的存储
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
bool g[1005][1005];
vector<int> v[1005];
void add(int x,int y){
    v[x].push_back(y);
    v[y].push_back(x);
    g[x][y] = 1;
    g[y][x] = 1;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        cout<<v[i].size()<<" ";
        sort(v[i].begin(),v[i].end());
        for(int j : v[i]) cout<<j<<' ';
        cout<<endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}