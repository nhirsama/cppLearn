//P1103 书本整理
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' ' <<
typedef pair<int, int> pii;
int dp[N][N], n, k; //一共选了i本，其中最后一本是j的最小不整齐度
pair<int, int> arr[N];

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr + 1, arr + n + 1);
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) dp[1][i] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = i-1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(arr[j].y - arr[k].y));
            }
        }
    }
    int minv = 0x3f3f3f3f;
    for (int i = n - k; i <= n; i++) {
        minv = min(minv, dp[n - k][i]);
    }
    cout << minv;
    return 0;
}
