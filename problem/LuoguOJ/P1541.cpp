//P1541 [NOIP 2010 提高组] 乌龟棋
#include <bits/stdc++.h>
using namespace std;
int n, m, arr[400], num[5], dp[42][42][42][42];

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        num[t]++;
    }
    for (int i = 0; i <= num[1]; i++) {
        for (int j = 0; j <= num[2]; j++) {
            for (int k = 0; k <= num[3]; k++) {
                for (int l = 0; l <= num[4]; l++) {
                    if (i) dp[i][j][k][l] = max(dp[i - 1][j][k][l], dp[i][j][k][l]);
                    if (j) dp[i][j][k][l] = max(dp[i][j - 1][k][l], dp[i][j][k][l]);
                    if (k) dp[i][j][k][l] = max(dp[i][j][k - 1][l], dp[i][j][k][l]);
                    if (l) dp[i][j][k][l] = max(dp[i][j][k][l - 1], dp[i][j][k][l]);
                    dp[i][j][k][l] += arr[1 + i + 2 * j + 3 * k + 4 * l];
                }
            }
        }
    }
    cout << dp[num[1]][num[2]][num[3]][num[4]] << endl;
    return 0;
}
