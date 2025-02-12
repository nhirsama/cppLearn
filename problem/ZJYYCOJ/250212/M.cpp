#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
vector<int> v[N];
const int mod = 1e9+7;
ll n;
ll dp[N][2];
bool st[N];
void bfs(int i){
    if (st[i]){return;}
    st[i] = true;
    dp[i][0] = 1;
    dp[i][1] = 1;
    for(int j:v[i]){
        if (st[j]) continue;
        bfs(j);
        dp[i][0] *= (dp[j][0]+dp[j][1]) % mod;
        dp[i][0] %= mod;
        dp[i][1] *= dp[j][0] % mod;
        dp[i][1] %= mod;
    }
}
int main() {
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);

    }
    bfs(1);
    cout<<(dp[1][0]+dp[1][1])%mod;
    return 0;
}
