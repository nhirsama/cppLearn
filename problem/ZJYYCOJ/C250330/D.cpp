//模板
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 2e6 + 10;
constexpr int mod = 998244353;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
i64 dp[N];

i64 pow(i64 a, int b, int m) {
    // 复杂度是 log N
    i64 r = 1 % m; /**! 这里的取模容易遗漏 */
    for (; b; b >>= 1, a = a * a % m) {
        if (b & 1) r = r * a % m;
    }
    return r;
}

void init() {
    dp[0] = 1;
    for (i64 i = 1; i < N; i++) {
        dp[i] = dp[i - 1] * i % mod;
    }
}

void nhir(i64 n) {
    std::cout << dp[n] * dp[n] % mod * pow(dp[2 * n + 1] % mod, mod - 2, mod) % mod << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    init();
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }

    while (std::cin >> T) nhir(T);
    return 0;
}
