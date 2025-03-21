//P3865 【模板】ST 表 && RMQ 问题
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

inline i32 read() {
    i32 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

i32 dp[N][25];

inline i32 query(i32 &l, i32 &r) {
    i32 log = 0;
    for (; (r - l + 1) >> log; log++) {
    };
    log--;
    return max(dp[l][log], dp[r - (1 << log) + 1][log]);
}

void nhir() {
    i32 n, m;
    n = read();
    m = read();
    for (i32 i = 1; i <= n; i++) {
        dp[i][0] = read();
    }
    for (i32 i = 1; i <= 22; i++) {
        for (i32 j = 1; j + (1 << i) - 1 <= n; j++) {
            dp[j][i] = max(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
        }
    }
    i32 l, r;
    while (m--) {
        l = read(), r = read();
        printf("%d\n", query(l, r));
    }
}

signed main() {
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        cin >> T;
    }

    while (T--) nhir();
    return 0;
}
