#define LOCAL
//P4779 【模板】单源最短路径（标准版）
//P3371 【模板】单源最短路径（弱化版）
//这题对于3371来说会TLE，所以bellman-ford不行 ，得用堆优化的dijkstra
//本代码是堆优化版的dijkstra
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5,M = 5e5+5;
vector<pair<int ,int> > g[N];
bool vist[N];
long long n,m,s,dist[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater< > >q;
void Dijkstra(){
    for(int i=1;i<=n;i++) {
        dist[i]=INT_MAX;
    }
    dist[s] = 0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int x = q.top().second;
        q.pop();
        if(vist[x])continue;
        vist[x] = true;
        for (auto &i : g[x]){
            if(dist[i.first] > dist[x] + i.second){
                dist[i.first] = dist[x] + i.second;
                q.push(make_pair(dist[i.first],i.first));
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif

    scanf("%lld%lld%lld",&n,&m,&s);
    for(int i = 1; i <= m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        g[a].push_back(make_pair(b,w));
    }
    Dijkstra();
    for(int i = 1; i <= n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}