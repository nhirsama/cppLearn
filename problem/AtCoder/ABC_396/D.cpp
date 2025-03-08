#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector g(n+1,vector<pair<ll,ll> >());
    for(int i = 1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    long long ans = (1ll<<63)-1;
    vector<int> st(n+1);
    auto bfs = [&](auto self,ll u,long long aa)->void{
        if(u == n){
            ans = min(aa,ans);
        }
        for(auto i : g[u]){
            if(st[i.x]) continue;
            st[i.x] = 1;
            self(self,i.x,aa^i.y);
            st[i.x] = 0;
        }
    };
    st[1] = 1;
    bfs(bfs,1,0);
    cout<<ans<<endl;
    return 0;
}
