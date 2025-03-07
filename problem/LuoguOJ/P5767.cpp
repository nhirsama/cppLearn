//P5767 [NOI1997] 最优乘车
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
vector<int> dist(N+1,0x3f3f3f3f),st(N+1);
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    int m,n;
    cin>>m>>n;
    vector g(n+1,vector<int>());
    for(int i = 0;i<=n;i++){
        string s;
        getline(cin,s);
        istringstream cinl(s);
        int v;
        vector<int> r;
        while(cinl>>v){
            r.push_back(v);
        }
        for(int j=0;j<r.size();j++){
            for(int k=j+1;k<r.size();k++){
                g[r[j]].push_back(r[k]);
            }
        }
    }
    auto spfa =  [&](){
        st[1] = 1;
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            st[u] = 0;
            for(auto v : g[u]){
                if(dist[v] > dist[u]+1){
                    dist[v] = dist[u]+1;
                    if(!st[v]){
                        st[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    };
    spfa();
    int ans = dist[n];
    if(ans > 0x3f3f3f3f/2) {
        cout<<"NO"<<endl;
    }
    else{
        cout<<ans-1<<endl;
    }
    return 0;
}
