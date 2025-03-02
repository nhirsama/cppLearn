//TLE
#include <bits/stdc++.h>
using namespace std;
const int N = 805;
int dp[N][N], pn[N];

int main() {
    int n, m, p;
    cin >> p >> n >> m;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= p; i++) {
        int t;
        cin >> t;
        pn[t]++;
    }
    for (int i = 1;i<=n;i++)dp[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = w;
        dp[v][u] = w;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (dp[j][k] > dp[j][i] + dp[i][k])dp[j][k] = dp[j][i] + dp[i][k];
            }
        }
    }
    long long dis = 0;
    long long ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        dis = 0;
        for (int j = 1; j <= n; j++) {
            dis += dp[i][j] * pn[j];
        }
        ans = min(ans, dis);
    }
    cout << ans;
}
