#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
void dfs(int u,int d,vector<vector<int> > &g,vector<int> &dp){

}
void Solve() {
    int n;
    cin>>n;
    vector<vector<int> > g(n+1),dist(n+1);
    vector<int > dp(n+1);
    for(int i = 2;i<=n;i++){
        int u;
        cin>>u;
        g[u].push_back(i);
        dist[i] = dist[u]+1;
    }
    dfs(1,0,g);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
