//  E - Payment Required
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> s(n), c(n);
    std::vector<double> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i] >> c[i] >> p[i];
        p[i] /= 100;
    }
    std::vector dp(x + 1, std::vector<double>((1 << n), 0.0));
    for (int i = 1; i <= x; i++) {
        for (int tt = 0; tt < (1 << n); tt++) {
            for (int j = 0; j < n; j++) {
                if ((!(tt & (1 << j))) && c[j] <= i) {
                    dp[i][tt] = std::max(
                        dp[i][tt], p[j] * (s[j] + dp[i - c[j]][tt | (1 << j)]) + (1.0 - p[j]) * dp[i - c[j]][tt]);
                }
            }
        }
    }
    printf("%.13f\n", dp[x][0]);
    //std::cout << std::format("{:.13f}\n", dp[x][0]);
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}