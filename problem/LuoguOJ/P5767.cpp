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
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    int m,n,be,en;
    cin>>m>>n>>be>>en;
    vector g(n+1,vector<pii>());
    for(int i = 1;i<=n;i++){
        string s;
        getline(cin,s);
        istringstream cinl(s);
        int u,v;
        cinl>>u;
        while(cinl>>v){
            g[u].push_back({v,0});
            u = v;
        }

    }
    return 0;
}
