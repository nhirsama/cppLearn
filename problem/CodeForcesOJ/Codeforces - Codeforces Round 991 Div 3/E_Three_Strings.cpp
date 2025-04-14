//  E. Three Strings
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
    std::string a, b, c;
    std::cin >> a >> b >> c;
    std::vector dp(a.size() + 1, std::vector<i32>(b.size() + 1));
    for (int i = 0; i < a.size(); i++) {
        dp[i + 1][0] = dp[i][0] + (a[i] == c[i]);
    }
    for (int j = 0; j < b.size(); j++) {
        dp[0][j + 1] = dp[0][j] + (b[j] == c[j]);
    }
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            dp[i][j] = std::max(dp[i - 1][j] + (a[i - 1] == c[i + j - 1]), dp[i][j - 1] + (b[j - 1] == c[i + j - 1]));
        }
    }
    // for (int i = 0; i <= c.size(); i++) {
    //     for (int j = 0; j <= i; j++) {
    //         i32 ap = j, bp = i - j;
    //         if (ap > a.size() || bp > b.size()) continue;
    //         if (ap > 0) {
    //             dp[ap][bp] = std::max(dp[ap][bp], dp[ap - 1][bp] + (a[ap - 1] == c[i - 1]));
    //         } else dp[ap][bp] = std::max(dp[ap][bp], 0 + (a[ap - 1] == c[i - 1]));
    //         if (bp > 0) dp[ap][bp] = std::max(dp[ap][bp], dp[ap][bp - 1] + (b[bp - 1] == c[i - 1]));
    //         else dp[ap][bp] = std::max(dp[ap][bp], 0 + (a[bp - 1] == c[i - 1]));
    // if(ap>=a.size() || bp>=b.size()) continue;
    // if(a[ap] == c[i]) {
    //     if(ap == 0) dp[ap][bp] = 0;
    //     else {
    //         dp[ap][bp] = std::min(dp[ap][bp],dp[ap-1][bp]);
    //     }
    // }
    // else {
    //     if(ap == 0) dp[ap][bp] = 1;
    //     else {
    //         dp[ap][bp] = std::min(dp[ap][bp],dp[ap-1][bp]+1);
    //     }
    // }
    // if(b[bp] == c[i]) {
    //     if(bp == 0) dp[ap][bp] = 0;
    //     else {
    //         dp[ap][bp] = std::min(dp[ap][bp],dp[ap][bp-1]);
    //     }
    // }
    // else {
    //     if(bp == 0) dp[ap][bp] = 1;
    //     else {
    //         dp[ap][bp] = std::min(dp[ap][bp],dp[ap][bp-1]+1);
    //     }
    // }
    //     }
    // }
    std::cout << c.size() - dp[a.size()][b.size()] << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
