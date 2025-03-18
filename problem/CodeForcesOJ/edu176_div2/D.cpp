//D. Equalization
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long
i64 dp[65][65];

void nhir() {
    i64 x,y, ans = 1ll << 60;
    cin >> x >> y;
    i32 xcnt = 0, ycnt = 0;
    for (i32 i = 0; i <= 60; i++) {
        for (i32 j = 0; j <= 60; j++) {
            if (x >> i == y >> j) {
                ans = min(ans, dp[i][j]);
            }
        }
    }
    // while ((x >> xcnt) != (y >> ycnt)) {
    //     if ((x >> xcnt) > (y >> ycnt)) {
    //         xcnt++;
    //     } else ycnt++;
    // }
    cout << ans << endl;
    // cout << (min(1ll,xcnt*1ll) << xcnt) + (min(1ll,ycnt*1ll) << ycnt) << endl;
}

signed main() {
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    //对于前i次除法，x除j次y除k的代价
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (i32 i = 0; i < 61; i++) {
        for (i32 j = 60; ~j; j--) {
            for (i32 k = 60; ~k; k--) {
                dp[min(60, i + j)][k] = min(dp[min(60, i + j)][k], dp[j][k] + (1ll << i));
                dp[j][min(60, k + i)] = min(dp[j][min(60, k + i)], dp[j][k] + (1ll << i));
            }
        }
    }
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
