#define LOCAL
//P1833 樱花
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T, n, ci[N], ti[N], cnt, dp[1005];

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int tsh, tsm, teh, tem;
    char c;
    cin >> tsh >> c >> tsm >> teh >> c >> tem >> n;
    T = (teh - tsh) * 60 + tem - tsm;
    for (int i = 1; i <= n; i++) {
        int c, p, t;
        scanf("%d%d%d", &t, &c, &p);
        if (p == 0) p = 1023;
        int pow2 = 1;
        while (pow2 <= p) {
            ci[++cnt] = c * pow2;
            ti[cnt] = t * pow2;

            p -= pow2;
            pow2 *= 2;
        }
        if (p) {
            ci[++cnt] = c * p;
            ti[cnt] = t * p;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = T; j >= ti[i]; j--) {
            dp[j] = max(dp[j], dp[j - ti[i]] + ci[i]);
        }
    }
    cout << dp[T] << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
