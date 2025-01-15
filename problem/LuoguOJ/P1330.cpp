#define LOCAL
//P1330 封锁阳光大学
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int n,m,rsize,bsize;
vector<int> v[10005],r,b;
vector<pair<int ,int> >vp;
bool visited[10005],flag,rv[10005],bv[10005];
void bfs(int a,bool q){
    if (flag)return;
    if(q){
        r.push_back(a);
        rv[a]=true;
    }
    else{
        b.push_back(a);
        bv[a]=true;
    }
    visited[a]=true;
    for (auto i:v[a]){
        if (q) {
            if (rv[i]) {
                flag=true;
                return;
            }
        }
        else {
            if (bv[i]) {
                flag=true;
                return;
            }
        }
        if(visited[i])continue;
        bfs(i,!q);

    }
    vp.push_back(make_pair(r.size()-rsize,b.size()-bsize));
    rsize = r.size();
    bsize = b.size();
}
int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P1330_2.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1;i<=n;i++){
        if(visited[i])continue;
        bfs(i,false);
    }
    int ans = 0;
    for (auto i:vp) {
        ans+=min(i.first,i.second);
    }
    if (flag) {
        puts("Impossible");
    }
    else cout<<ans<<endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
