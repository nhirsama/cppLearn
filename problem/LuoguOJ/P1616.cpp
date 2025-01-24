#define LOCAL
//P1616 疯狂的采药
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
//四年ACM一场空，不开long long 见祖宗
long long t, m, dp[N];

struct node {
    int a, b;
} arr[N];

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[i].a = a;
        arr[i].b = b;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = arr[i].a; j <= t; j++) {
            dp[j] = max(dp[j], dp[j - arr[i].a] + arr[i].b);
        }
    }
    cout << dp[t] << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
