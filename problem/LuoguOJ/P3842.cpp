//P3842 [TJOI2007] 线段
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e4 + 10;
int n, dp[N][2];
pair<int, int> arr[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    dp[1][0] = arr[1].second - 1 + (arr[1].second - arr[1].first);
    dp[1][1] = arr[1].second - 1;
    for (int i = 2; i <= n; i++) {
        int len = arr[i].second - arr[i].first;
        dp[i][0] = min(abs(arr[i - 1].first - arr[i].second) + dp[i - 1][0],
                       abs(arr[i - 1].second - arr[i].second) + dp[i - 1][1]) + len + 1;
        dp[i][1] = min(abs(arr[i - 1].first - arr[i].first) + dp[i - 1][0],
                       abs(arr[i - 1].second - arr[i].first) + dp[i - 1][1]) + len + 1;
    }
    int ans = min(dp[n][0] + n - arr[n].first, dp[n][1] + n - arr[n].second);
    cout << ans;
}
