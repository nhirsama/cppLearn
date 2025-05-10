#include<bits/stdc++.h>

using namespace std;

#define int long long
using PII = pair<int,int>;
const int N = 5e5+10;
int n,m,q,V;
int fa[N];
vector<vector<PII>>adj;
vector<int>p;
vector<PII>qs;
vector<int>ans;

inline int lowbit(int x){
    return x&(-x);
}

inline void add(int u,int v,int w){
    adj[u].push_back({v,w});
}

inline int find(int x){
    while(x!=fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

void bfs(int u,int x){
    queue<int>q;
    q.push(u);
    p[u] = u;
    while(q.size()){
        int t = q.front();
        q.pop();
        for(auto &edge:adj[t]){
            int v = edge.first;
            int w = edge.second;
            if(p[v] || (w&x)!=x) continue;
            q.push(v);
            p[v] = u;
        }
    }

}

void work(int x){
    p.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(!p[i]) bfs(i,x);
    }

    for(int i=1;i<=q;i++){
        int u = qs[i].first;
        int v = qs[i].second;
        if(!ans[i]) ans[i] = (p[u] == p[v]);
    }
}

void solve(){
    cin>>n>>m>>q>>V;
    adj.resize(n+1);
    qs.resize(q+1);
    ans.resize(q+1);
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w); add(v,u,w);
    }

    for(int i=1;i<=q;i++){
        cin>>qs[i].first>>qs[i].second;
    }

    int t = 1LL<<60;
    if(V==0){
        work(0);
        // cout<<"work1\n";
    }else{
        // cout<<"work2\n";
        for(int i=V;i<t;i+=lowbit(i)){
            work(i);
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout<<fa[i]<<' ';
    // }
    for(int i=1;i<=q;i++){
        cout<<(ans[i]?"Yes\n":"No\n");
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}