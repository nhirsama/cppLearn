#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
int dp[120][100][100];
int m,n;
void dpFunc() {
    for (int i = 2; i <= m+n; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 1; k < i; k++) {
                dp[i][j][k] = max(max(dp[i-1][j][k],dp[i-1][j-1][k]),max(dp[i-1][j][k-1],dp[i-1][j-1][k-1]));
                dp[i][j][k] += arr[j][i-j]+arr[k][i-k];
                if (j == k) dp[i][j][k] -= arr[j][i-j];
            }
        }
    }
}
int main() {
    cin >> m>>n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <=n;j++) {
            cin >> arr[i][j];
        }
    }
    dpFunc();
    int max1= 0;
    for (int i = 1; i <= n+m; i++) {
        for (int j = 1; j <= n+m;j++) {
            if(dp[m+n][i][j] > max1) max1 = dp[m+n][i][j];
        }
    }
    cout << max1 << endl;
    return 0;
}