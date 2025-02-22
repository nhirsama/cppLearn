//P2858 [USACO06FEB] Treats for the Cows G/S
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2020;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

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
int dp[N][N],n,vi[N];
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    n = read();
    for (int i = 1; i <= n; i++) {
        vi[i] = read();
        dp[i][i] = vi[i]*n;
    }
    for(int len = 2; len <= n; len++) {
        for(int l = 1,r = len; r <= n; l++,r++) {
            dp[l][r] = max(dp[l][r],max(dp[l+1][r]+vi[l]*(n-len+1),dp[l][r-1]+vi[r]*(n-len+1)));
        }
    }
    cout << dp[1][n] endl;
    return 0;
}
