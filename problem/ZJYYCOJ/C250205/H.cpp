#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> g[N];
bool st[N];
int n,m,root[N],dist[N],edge[N];
int find(int x){
    return root[x] == x ? x : root[x] = find(root[x]);
}
int main(){
    cin>>n>>m;
    bool flag = true;
    if(m>n) {
        puts("No");
        return 0;
    }
    for(int i=0;i<=n;i++) root[i] = i;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
        root[find(x)] = find(y);
    }
    for(int i=1;i<=n;i++){
        dist[find(i)]++;
        edge[find(i)]+=g[i].size();
    }
    for(int i=1;i<=n;i++){
        if(dist[i]!=edge[i]/2) flag = false;
    }

    if(flag) puts("Yes");
    else puts("No");
    return 0;
}