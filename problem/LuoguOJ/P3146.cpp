//P3146 [USACO16OPEN] 248 G
//区间dp
//一次AC，大水题
#include <bits/stdc++.h>
using namespace std;
const int N  = 250;
int arr[N],dp[N][N],n,ans;
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dp[i][i]);
        ans = max(ans, dp[i][i]);
    }
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i+len-1 <= n; i++) {
            int l = i, r = i+len-1;
            for(int j = l; j < r; j++) {
                if(dp[l][j] == dp[j+1][r] && dp[l][j]) {
                    dp[l][r] = max(dp[l][r], dp[j+1][r]+1);
                    ans = max(ans, dp[l][r]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
