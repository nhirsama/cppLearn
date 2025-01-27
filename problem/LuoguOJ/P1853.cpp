#define LOCAL
//P1853 投资的最大效益
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int s, n, d, a[15], b[15], dp[N*40];

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> s >> n >> d;
    int m = s%1000;
    s/=1000;
    for (int i = 1; i <= d; i++) {
        scanf("%d%d", &a[i], &b[i]);
        a[i]/=1000;
    }
    for (int i = 1; i <= n; i++) {
        memset(dp, 0, sizeof dp);
        for (int j = 1; j <= d; j++) {
            for (int k = a[j]; k <= s; k++) {
                dp[k] = max(dp[k], dp[k - a[j]] + b[j]);
            }
        }
        m+=dp[s]%1000;
        s+=dp[s]/1000;
        s+=m/1000;
        m%=1000;
    }
    cout << s*1000+m;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
