//P11669 [USACO25JAN] Cow Checkups B
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 7500 + 10;
typedef long long int ll;
#define endl << '\n'

inline ll read() {
    ll ans = 0;
    bool flag = false;
    char c = cin.get();
    while (c < '0' || c > '9') {
        if (c == '-') flag = true;
        c = cin.get();
    }
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = cin.get();
    if (flag) return -ans;
    return ans;
}

int sum[N], arr[N], barr[N], n, ans[N];
int dp[N][N];

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    n = read();
    for (int i = 1; i <= n; i++) {
        arr[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        barr[i] = read();
        sum[i] += sum[i - 1] + (barr[i] == arr[i]);
        dp[i][i] = barr[i] == arr[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1,r = l+len-1; r <= n; l++, r++) {
            dp[l][r] = dp[l+1][r-1]+(arr[r] == barr[l])+(arr[l] == barr[r]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans[dp[i][j]+sum[n]-sum[j]+sum[i-1]]++;
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << ans[i] endl;
    }
    return 0;
}
