#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;
ll n, k;
int arr[N], dp[N][105][2];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(dp, -0x3f, sizeof dp);
    for (int i = 0; i <= n; i++) dp[i][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + arr[i]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - arr[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) ans = max(ans, dp[n][i][0]);
    cout << ans;
    return 0;
}
