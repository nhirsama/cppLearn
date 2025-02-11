//P5662 [CSP-J2019] 纪念品
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
typedef long long int ll;
int dp[105][N],arr[105][105],t,n,m;
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    int money = m;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = arr[i][j]; k <= money; k++) {
                dp[i][k] = max(dp[i][k],dp[i][k-arr[i][j]]+arr[i+1][j]-arr[i][j]);
            }
        }
        money=max(money,money+dp[i][money]);
    }
    cout << money << endl;
    return 0;
}
