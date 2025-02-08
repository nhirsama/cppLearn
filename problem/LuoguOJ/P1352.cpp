//P1352 没有上司的舞会
#include <bits/stdc++.h>
using namespace std;
const int N = 6e3 + 10;
int n, r[N], dp[N][2];
bool isRoot[N], st[N];
vector<int> v[N];

void dfs(int i) {
    st[i] = true;
    for (int j = 0; j < v[i].size(); j++) {
        if (st[v[i][j]]) continue;
        dfs(v[i][j]);
        dp[i][1] += dp[v[i][j]][0];
        dp[i][0] += max(dp[v[i][j]][1], dp[v[i][j]][0]);
    }
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++)scanf("%d", &dp[i][1]);
    for (int i = 1; i <= n; i++) {
        int l, k;
        scanf("%d%d", &l, &k);
        v[k].push_back(l);
        isRoot[l] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!isRoot[i]) {
            dfs(i);
            cout << max(dp[i][0], dp[i][1]) << endl;
        }
    }
    return 0;
}
