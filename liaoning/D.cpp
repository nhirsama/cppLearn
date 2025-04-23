#include <bits/stdc++.h>
using namespace std;
using pii = std::pair<int, int>;

long double dist(pii &a, pii &b) {
    long double d1 = a.first - b.first, d2 = a.second - b.second;
    return sqrt(d1 * d1 + d2 * d2);
}

int main() {
    int n;
    std::cin >> n;
    //std::vector d(n + 1, vector<long double>(n + 1));
    std::vector dmax(n + 1, vector<long double>(n + 1));
    std::vector<pii> point(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> point[i].first >> point[i].second;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            //d[i][j] = dist(point[i], point[j]);
            dmax[i][j] = max(dmax[i][j - 1], dist(point[i], point[j]));
        }
    }
    vector<long double> dp(n + 1);
    // vector dp(n + 1, vector<long double>(n + 1));
    // for (int i = 1; i <= n; i++) { //j是结束的点，i是开始的点.
    //     for (int j = 1; j <= i; j++) {
    //         dp[j][i] = d[j][i] + dp[1][j-1];
    //     }
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + i <= n; j++) {
            dp[i + j] = max(dp[i + j], dp[i - 1] + dmax[i][i + j]);
        }
    }
    //long double ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     ans = max(ans, dp[n]);
    // }
    // long double ans = 0;
    // vector<int> poset;
    // long double nd = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (poset.size()) {
    //         long double lnd = 0;
    //         for (auto j: poset) {
    //             lnd = max(lnd, d[j][i]);
    //         }
    //         if (lnd >= nd) {
    //             nd = lnd;
    //             poset.push_back(i);
    //         } else {
    //             ans += nd;
    //             nd = 0;
    //             poset.clear();
    //             poset.push_back(i);
    //         }
    //     } else {
    //         poset.push_back(i);
    //     }
    // }
    // ans += nd;
    printf("%.20Lf", dp[n]);
}
