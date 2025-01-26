#define LOCAL
//P1466 [USACO2.2] 集合 Subset Sums
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int n, dp[N][20 * 40];

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int sum = (1 + i) * i / 2;
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)dp[i][j] += dp[i - 1][j - i];
        }
    }
    if (n * (n + 1) % 4 == 0)cout << dp[n][n * (n + 1) / 4] << endl;
    else cout << 0 << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
