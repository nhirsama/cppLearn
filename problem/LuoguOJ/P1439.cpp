#define LOCAL
//P1439 【模板】最长公共子序列
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int LIS[N],n1[N],n2[N];
int cnt;
int main() {
    #ifdef LOCAL
    freopen("inAndoutFile/P1439_4.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> n1[i];
    }
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        n2[a] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (n2[n1[i]] > LIS[cnt]) {
            LIS[++cnt] = n2[n1[i]];
        }
        else {
            int a = upper_bound(LIS+1, LIS+cnt+1, n2[n1[i]]) - LIS;
            LIS[a] = n2[n1[i]];
        }
    }
    cout << cnt << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
/*
int a1[N], a2[N];
int dp[1005][1005];
//数组太大会re
//int dp[N][N];
//考虑其他做法
int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a1[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a2[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a1[i] == a2[j]) dp[i][j] = max(dp[i-1][j-1] + 1,dp[i][j]);
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][n] << endl;

    return 0;
}
*/
