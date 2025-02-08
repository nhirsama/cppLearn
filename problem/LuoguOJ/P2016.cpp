//P2016 战略游戏
#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
vector<int> g[N];
int dp[N][2], n;
bool isRoot[N], vis[N];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    dp[u][1] = 1;
    for (int i : g[u]) {
        dfs(i);
        dp[u][0] += dp[i][1];
        dp[u][1] += min(dp[i][0],dp[i][1]);
    }

}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u;
        int k;
        scanf("%d%d", &u, &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            g[u].push_back(v);
            isRoot[v] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!isRoot[i]) {
            dfs(i);
            cout << min(dp[i][0],dp[i][1]) << endl;
        }
    }
    return 0;
}
