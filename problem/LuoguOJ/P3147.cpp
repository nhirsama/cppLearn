//P3147 [USACO16OPEN] 262144 P
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
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

int arr[N], dp[60][N], n;

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
        dp[arr[i]][i] = i+1;
    }
    int ans = 0;
    for (int i = 2; i < 60; i++) {
        for (int j = 1; j <= n; j++) {
            if (!dp[i][j]) dp[i][j] = dp[i - 1][dp[i - 1][j]];
            if (dp[i][j]) ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
