//P11668 [USACO25JAN] It's Mooin' Time II B
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10;
typedef long long int ll;
int dp[N][3];
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0;
    ll ans = 0;
    cin>>n;
    int cnt = 0;
    while (n--) {
        int m;
        cin>>m;
        cnt += 1-dp[m][2];
        dp[m][2] = 1;
        dp[m][1] = dp[m][0];
        dp[m][0] = cnt-1;
    }
    for(int i = 1; i < N; i++) {
        ans +=dp[i][1];
    }
    cout << ans<< endl;
    return 0;
}
