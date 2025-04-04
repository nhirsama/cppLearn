//D
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 3e5 + 10;
constexpr int mod = 998244353;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
i64 dp[N];

i64 pow(i64 a, i32 b) {
    // 复杂度是 log N
    i64 r = 1 % mod; /**! 这里的取模容易遗漏 */
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) r = r * a % mod;
    }
    return r;
}

void init() {
    dp[0] = 1;
    for (i64 i = 1; i < N; i++) {
        dp[i] = dp[i - 1] * i % mod;
    }
}
void nhir() {
    std::vector<int> v(26);
    int sum = 0;
    for (auto &i:v) {
        std::cin >> i;
        sum += i;
    }

    if (!sum) {
        std::cout << "0\n";
        return;
    }

    int k = (sum + 1) / 2;
    int m = sum / 2;
    for (int x : v) {
        if (x>(sum + 1) / 2) {
            std::cout << "0\n";
            return;
        }
    }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin>>T;
    init();
    while (T--) nhir();
    return 0;
}
