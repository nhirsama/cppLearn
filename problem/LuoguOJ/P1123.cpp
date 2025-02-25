//P1123 取数游戏
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define endl '\n'
ll dp[8][1 << 7], n, m;
vector<int> vll;
int arr[10][10];

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

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = read();
    for (int i = 0; i < (1 << 6); i++) {
        if ((i << 1) & i) continue;
        vll.push_back(i);
    }
    while (t--) {
        n = read();
        m = read();
        int p = 1 << m;
        memset(dp, 0, sizeof dp);
        memset(arr, 0, sizeof arr);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < vll.size() && vll[j] < p; j++) {
                for (int k = 0; k < vll.size() && vll[k] < p; k++) {
                    if (vll[j] & vll[k])continue;
                    if (((vll[j] | vll[k]) << 1) & (vll[j] | vll[k]))continue;
                    ll sum = 0;
                    int te = vll[k], cnt = 1;
                    while (te) {
                        if (te & 1)sum += arr[i][cnt];
                        te >>= 1;
                        cnt++;
                    }
                    dp[i][vll[k]] = max(dp[i][vll[k]], sum + dp[i - 1][vll[j]]);
                }
            }
        }
        ll ans = 0;
        for (auto i: vll) ans = max(dp[n][i], ans);
        cout << ans << endl;
    }
    return 0;
}
