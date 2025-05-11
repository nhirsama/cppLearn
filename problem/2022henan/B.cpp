//
// Created by ling on 25-5-11.
//
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i32 = i64;
const i32 mod = 998244353;

int main() {
    string ins;
    cin >> ins;
    auto hash = [](char c) {
        if (c == 'n') {
            return 4;
        } else if (c == 'h') {
            return 3;
        } else if (c == 'e') {
            return 2;
        } else if (c == 'a') {
            return 1;
        }
        return 0;
    };
    // auto hash = [](string t) {
    //     i32 res = 0, base = 1;
    //     if (t.size() == 0) return 0ll;
    //     for (i32 i = t.size() - 1; ~i; i--) {
    //         if (t[i] == 'n') {
    //             res += base * 4;
    //         } else if (t[i] == 'h') {
    //             res += base * 3;
    //         } else if (t[i] == 'e') {
    //             res += base * 2;
    //         } else if (t[i] == 'a') {
    //             res += base * 1;
    //         }
    //         base *= 31;
    //         base %= mod;
    //         res %= mod;
    //     }
    //     return res % 998244353;
    // };
    i32 n = ins.size();
    string s = ins + ins;
    // vector<i32> ghash(n * 2 + 1);
    // i32 pow = 1;
    // for (i32 i = 0; i < 2 * n; i++) {
    //     ghash[i + 1] = (pow * hash(s[i]) + ghash[i]) % mod;
    //     pow *= 31;
    //     pow %= mod;
    // }
    i32 ans = 0;
    i32 D = 15;
    vector<i32> dp(n + 1);
    i32 INF = 0x3f3f3f3f3f3f3f3f;
    for (int st = 0; st < n && st < D; st++) {
        fill(dp.begin(), dp.end(), -INF);
        dp[0] = 0;
        for (int len = 1; len <= n; len++) {
            for (int k = 1; k <= D && k <= len; k++) {
                // i64 h = hash(s.substr(st + len - k, k));
                i64 h = (ghash[st + len] - ghash[st + len - k - 1] + mod) % mod;
                dp[len] = max(dp[len], dp[len - k] + h);
            }
        }
        ans = max(ans, dp[n]);
    }
    std::cout << ans << endl;
    // std::vector<i32> dp(n * 2);
    // for (i32 i = 0; i < min(20ll, n); i++) {
    //     for (i32 j = i; j < i + n; j++) {
    //         for (i32 k = 1; k <= D && k <= j - i + 1; k++) {
    //             // 取 [j-k+1, j] 这 k 个字符
    //             dp[j] = max(dp[j], dp[j - k] + hash(s.substr(j - k + 1, k)));
    //         }
    //
    //         // for (i32 k = 0; k < min(15ll, j - i); k++) {
    //         //     // dp[j] = max(dp[j], (dp[j - k] + hash(s.substr(j - k, k)) % 998244353));
    //         //     dp[j] = max(dp[j], dp[j - k] + hash(s.substr(j - k + 1, k)));
    //         // }
    //         // for (i32 k = 1; k < min(j, 10ll); k++) {
    //         //     dp[j] = max(dp[j], (dp[j - k] + hash(s.substr(j - k, k)) % 998244353));
    //         // }
    //     }
    //     for (i32 k = i; k < i + n; k++) {
    //         ans = max(ans, dp[k]);
    //     }
    //     //dp = vector<i32>(n * 2, 0);
    //     // ans = max(ans,dp[])
    // }
    //for (i32 i = n - 1; i < n * 2; i++) ans = max(ans, dp[i]);
    //std::cout << ans << endl;
    // for (i32 i = 0; i <= min(100ll, n); i++) {
    //     string base;
    //     for (i32 j = i; j < n + i; j++) {
    //         if (hash(base + s[j]) < 998244353) base += s[j];
    //         else {
    //             ans += hash(base);
    //             base = s[j];
    //         }
    //         // if (hash(base + s[j]) > hash(base)) base += s[j];
    //         // else {
    //         //     ans += hash(base);
    //         //     base = s[j];
    //         // }
    //     }
    //     ans += hash(base);
    //     res = max(ans, res);
    //     ans = 0;
    //     //std::cout<<hash(ins)<<endl;
}
