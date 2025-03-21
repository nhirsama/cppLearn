//P2822 [NOIP 2016 提高组] 组合数问题
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 2e3 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long
i32 dp[N][N]{};
i32 cnt[N][N]{0};
i32 k;

void init() {
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            dp[i][j] %= k;
            if (dp[i][j] == 0) cnt[i][j] = cnt[i][j - 1] + 1;
            else cnt[i][j] = cnt[i][j - 1];
        }
    }
}

void nhir() {
    i32 n, m;
    cin >> n >> m;
    i64 ans = 0;
    for (i32 i = 0; i <= n; i++) {
        ans += cnt[i][min(i, m)];
    }
    cout << ans << endl;
}

signed main() {
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    IOS;
    i32 T = 1;
    cin >> T >> k;
    init();

    while (T--) nhir();
    return 0;
}
