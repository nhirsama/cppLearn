//B
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (auto &i: a) {
        std::cin >> i;
    }
    std::vector<i64> suf(n + 1);
    for (int i = 1; i <= n; i++) {
        suf[i] = suf[i - 1] + a[n - i];
    }
    std::vector<i64> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = std::max(dp[i - 1], a[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        std::cout << suf[i - 1] + dp[n - i + 1];
        if (i < n) std::cout << " ";
    }
    std::cout << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
