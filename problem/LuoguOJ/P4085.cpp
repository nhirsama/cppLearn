//P4085 [USACO17DEC] Haybale Feast G
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

i64 dp[N][25];
i64 qsum[N];

inline i64 query(i32 &l, i32 &r) {
    i32 log = 0;
    if (r < l) return 0x3f3f3f3f3f3f3f;
    for (; (r - l + 1) >> log; log++) {
    };
    log--;
    return max(dp[l][log], dp[r - (1 << log) + 1][log]);
}

void nhir() {
    i64 n;
    i64 m;
    cin >> n >> m;
    for (i32 i = 1; i <= n; i++) {
        cin >> qsum[i] >> dp[i][0];
        qsum[i] += qsum[i - 1];
    }
    for (i32 i = 1; i <= 22; i++) {
        for (i32 j = 1; j + (1 << i) - 1 <= n; j++) {
            dp[j][i] = max(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
        }
    }
    i32 l = 1, r = 1;
    i64 ans = 0x3f3f3f3f3f3f3f3f;
    for (; r <= n; r++) {
        if (qsum[r] - qsum[l - 1] >= m)ans = min(ans, query(l, r));
        while (l < r && (qsum[r] - qsum[l] >= m)) {
            l++;
            ans = min(ans, query(l, r));
        }
    }
    cout << ans << endl;
}

signed main() {
    freopen("inAndoutFile/P4085_4.in", "r", stdin);
    freopen("Code.out", "w", stdout);
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
