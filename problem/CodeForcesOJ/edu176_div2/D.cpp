//模板
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
vector<i64> dp(200, 1ll << 62);

void nhir() {
    i64 x,y;
    cin >> x >> y;
    i32 xcnt = 0, ycnt = 0;
    while ((x >> xcnt) != (y >> ycnt)) {
        if ((x >> xcnt) > (y >> ycnt)) {
            xcnt++;
        } else ycnt++;
    }
    cout << dp[xcnt + ycnt] << endl;
    // cout << (min(1ll,xcnt*1ll) << xcnt) + (min(1ll,ycnt*1ll) << ycnt) << endl;
}

signed main() {
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    vector<bool> st(200);
    dp[0] = 0;
    for (i32 a = 0; a <= 180; ++a) {
        for (i32 x = 180; x >= a; --x) {
            if (dp[x - a] != 1ll << 62) {
                i64 cost;
                if (a > 60) cost = dp[x - a] + (1LL << 61);
                else cost = dp[x - a] + (1LL << a);
                if (cost < dp[x]) {
                    dp[x] = cost;
                }
            }
        }
    }
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
