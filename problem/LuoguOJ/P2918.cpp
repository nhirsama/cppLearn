#define LOCAL
//P1144 最短路计数
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
//严格来说可能会存在H=5e4，c1=5000、p1=1的情况，但是不管那么多了，re了再说（）
const int N = 55010;
int H, n, pi[105], ci[105], dp[N];

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> H;
    for (int i = 1; i <= n; i++) {
        cin >> pi[i] >> ci[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = pi[i]; j <= H + 5000; j++) {
            dp[j] = min(dp[j], dp[j - pi[i]] + ci[i]);
        }
    }
    int min1 = 0x3f3f3f3f;
    for (int i = H; i <= H+5000; i++) {
        min1 = min(min1, dp[i]);
    }
    cout << min1 << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
