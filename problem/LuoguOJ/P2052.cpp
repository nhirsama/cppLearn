//P2052 [NOI2011] 道路修建
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
typedef long long int ll;
vector<pair<int,int>> v[N];
ll n,w;
ll dp[N],ans;
bool vis[N];
void dfs(int i){
    vis[i] = true;
    dp[i] = 1;
    for(auto j:v[i]){
        if (vis[j.first])continue;
        dfs(j.first);
        dp[i] += dp[j.first];
        ans+=abs(n-dp[j.first]*2)*j.second;
    }
}
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
