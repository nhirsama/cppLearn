//P1063 [NOIP 2006 提高组] 能量项链
#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n,dp[N][N];
pair<int, int> arr[N];
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i-1].second = arr[i].first;
        arr[i+n].first = arr[i].first;
        arr[i+n-1].second = arr[i].first;
    }
    arr[n].second = arr[1].first;
    arr[2*n].second = arr[1].first;
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i+len-1 <= 2*n; i++) {
            int l = i, r = i+len-1;
            for(int j = l; j < r; j++) {
                dp[l][r] = max(dp[l][r] , dp[l][j]+dp[j+1][r] + arr[l].first*arr[j].second*arr[r].second);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans , dp[i][i+n-1]);
    }
    cout << ans << endl;
    return 0;
}
