#define LOCAL
//P2851 [USACO06DEC] The Fewest Coins G
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<vector<pair<int, int> > > g(105);
int m, n, dp[N];

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[c].push_back(make_pair(a, b));
    }
    for (int i = 1; i < 101; i++) {
        if (g[i].empty()) { continue; }
        for (int j = m; j >= 0; j--) {
        for (int k = 0; k < g[i].size(); k++) {
               if (g[i][k].first <= j) {
                   dp[j] = max(dp[j], dp[j - g[i][k].first] + g[i][k].second);
               }
            }
        }
    }
    cout << dp[m];
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
