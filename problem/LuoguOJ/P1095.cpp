#define LOCAL
//P1095 [NOIP 2007 普及组] 守望者的逃离
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int m, s, t, ans, dp[N][2];
bool flag = false;

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> m >> s >> t;
    for (int i = 1; i <= t; i++) {
        if (m >= 10) {
            dp[i][0] = dp[i - 1][0] + 60;
            m -= 10;
            dp[i][1] = max(dp[i - 1][0] + 60,dp[i-1][1]+17);
        } else {
            dp[i][0] = dp[i - 1][0];
            m += 4;
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 17;
        }
    }
    if (max(dp[t][0], dp[t][1]) >= s) {
        flag = true;
    }
    if (flag) {
        puts("Yes");
        for (int i = t; i; i--) {
            if (max(dp[i][0],dp[i][1]) >= s) ans = i;
        }
    } else {
        puts("No");
        ans = max(dp[t][1],dp[t][0]);
    }
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
