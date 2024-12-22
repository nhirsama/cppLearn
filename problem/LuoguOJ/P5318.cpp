#define LOCAL
//P5318 【深基18.例3】查找文献
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int e[N],ne[N],h[N],idx = 0;
bool visited[N];
int m,n;
void add(int x,int y){
    e[++idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
}
void dfs(int x){
    visited[x] = true;
    cout<<x<<" ";
    vector<int> v;
    for(int i = h[x]; e[i] && i; i = ne[i]){
        if(visited[e[i]])continue;
        v.push_back(e[i]);
    }
    sort(v.begin(), v.end());
    for (auto i:v) {
        if (visited[i]) continue;
        dfs(i);
    }
}
void bfs(int x){
    memset(visited,0,4*n+10);
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        cout<<t<<" ";
        vector<int> v;
        for (int i = h[t]; e[i] && i; i = ne[i]) {
            if(visited[e[i]]) continue;
            v.push_back(e[i]);
            visited[e[i]] = true;
        }
        sort(v.begin(), v.end());
        for (auto i:v) {
            q.push(i);
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    dfs(1);
    cout<<endl;
    bfs(1);
    cout<<endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}