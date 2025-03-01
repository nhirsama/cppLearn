#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
long long dist[N];
bool st[N];

void dijkstra(vector<vector<pair<int,int> > > g,int u)  // 求1号点到n号点的最短路距离
{
    memset(st,0,sizeof st);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, u});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (auto i : g[ver])
        {
            int j = i.x;
            if (dist[j] > dist[ver] + i.y)
            {
                dist[j] = dist[ver] + i.y;
                heap.push({dist[j], j});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,x;
    cin>>n>>m>>x;
    vector<vector<pair<int,int> > >g(N);
    vector<vector<pair<int,int> > > exg(N);
    for(int i = 1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(make_pair(v,1));
        exg[v].push_back(make_pair(u,1));
    }
    memset(dist, 0x3f, sizeof dist);
    int cnt =-1;
    int u = 1;
    while(dist[n]>0x3f3f3f3f3f3f3f3f/2){
      cnt++;
        if(cnt%2==0)dijkstra(g,u++);
        else dijkstra(exg,u++);
    }
    cout<<dist[n]+cnt*m;
    return 0;
}
