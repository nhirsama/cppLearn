#define LOCAL
//P1507 NASA的食物计划
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int dp[55][N][N], h, t, n;

struct node {
    int v, m, k;
} arr[55];

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> h >> t >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        arr[i] = (node){a, b, c};
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= h; j++) {
            for (int k = 0; k <= t; k++) {
                if (arr[i].v > j || arr[i].m > k) dp[i][j][k] = dp[i - 1][j][k];
                else dp[i][j][k] = max(dp[i - 1][j - arr[i].v][k - arr[i].m] + arr[i].k, dp[i - 1][j][k]);
            }
        }
    }
    cout << dp[n][h][t] << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
