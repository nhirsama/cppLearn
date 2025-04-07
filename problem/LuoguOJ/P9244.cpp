//P9244 [蓝桥杯 2023 省 B] 子串简写
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 5e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
i64 dp[N][2];

void nhir() {
    i32 k;
    std::string s;
    char a, b;
    std::cin >> k >> s >> a >> b;
    for (i32 i = 0; i < s.size(); i++) {
        if (i) dp[i][0] = dp[i - 1][0], dp[i][1] = dp[i - 1][1];
        if (s[i] == a) {
            dp[i][0]++;
        }
        if (s[i] == b) {
            if (i >= k - 1) dp[i][1] += dp[i - k + 1][0];
        }
    }
    std::cout << dp[s.size() - 1][1] << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }

    while (T--) nhir();
    return 0;
}
