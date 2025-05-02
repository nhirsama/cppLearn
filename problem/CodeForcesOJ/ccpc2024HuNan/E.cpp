#include <bits/stdc++.h>
using namespace std;
int dp[(1 << 18) + 10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    std::cin >> n;
    //int ttt = 0;
    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
        v[i] = 1 << --v[i];
    }
    // set<int> s;
    // int ttt = 0, cntt = 0;

    for (int i = 1; i <= n; i++) {
        int t = v[i];
        dp[t] = 1;
        for (int j = 1; j < 18 && j + i <= n; j++) {
            if (t & v[i + j]) break;
            t |= v[i + j];
            dp[t] = j + 1;
        }
    }
    // for (int i = (1 << 18) - 1; i; i--) {
    //     for (int j = 0; j <= 18; j++) {
    //         //if (i & (1 << j)) continue;
    //         dp[i] = max(dp[i], dp[(i >> j) << j] + dp[((1 << j) - 1) & i]);
    //         //dp[i | (1 << j)] = max(dp[i] + dp[1 << j], dp[i | (1 << j)]);
    //         //dp[i] = max(dp[i], dp[i | (1 << j)]);
    //     }
    // }
    for (int i = 0; i < 1 << 18; i++) {
        for (int j = 0; j < 18; j++) {
            if (i & (1 << j)) {
                dp[i] = max(dp[i], dp[i ^ (1 << j)]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 1 << 18; i++) {
        ans = max(ans, dp[i] + dp[((1 << 18) - 1) ^ i]);
    }
    // vector<int> vv[19];
    // for (auto i: s) {
    //     vv[__builtin_popcount(i)].push_back(i);
    //     //if (cntt < __builtin_popcount(i)) ttt = i, cntt = __builtin_popcount(i);
    // }
    // int ans = cntt;
    // for (auto i: s) {
    //     if (ttt & i) continue;
    //     ans = max(ans, __builtin_popcount(i | ttt));
    // }
    // for (auto i: s) {
    //     //std::cout << i << endl;
    //     ans = max(ans, __builtin_popcount(i));
    //     for (auto j: s) {
    //         if (j & i) continue;
    //         ans = max(ans, __builtin_popcount(j | i));
    //         if (ans == 18) {
    //             std::cout << 18 << endl;
    //             return 0;
    //         }
    //     }
    // }
    std::cout << ans << endl;
}
