//P9242 [蓝桥杯 2023 省 B] 接龙数列
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
    i64 n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector next(10, std::priority_queue<i32>());
    std::vector<i32> dp(n);
    for (i32 i = 0; i < n; i++) {
        if (next[v[i][0] - '0'].size() == 0) {
            dp[i] = 1;
            next[v[i].back() - '0'].push({1});
        } else {
            dp[i] = next[v[i][0] - '0'].top() + 1;
            next[v[i].back() - '0'].push(dp[i]);
        }
    }
    i32 max = 0;
    for (auto i: dp) {
        max = std::max(max, i);
    }
    std::cout << n - max << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }

    while (T--) nhir();
    return 0;
}
