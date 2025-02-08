//P2014 [CTSC1997] 选课
#include <bits/stdc++.h>
using namespace std;
const int N = 305;
vector<int> v[N];
int dp[N][N], n, m, c[N];
bool vis[N];

void dfs(int u) {
    dp[u][1] = c[u];
    for (int i: v[u]) {
        dfs(i);
    }
    for (int i: v[u]) {
        for (int j = m; j; j--) {
            for (int k = 0; k < j; k++) {
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[i][k]);
            }
        }
    }
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> n >> m;
    m++;
    for (int i = 1; i <= n; i++) {
        int k, s;
        scanf("%d %d", &k, &s);
        v[k].push_back(i);
        c[i] = s;
    }
    dfs(0);
    cout << dp[0][m] << "\n";
    return 0;
}
