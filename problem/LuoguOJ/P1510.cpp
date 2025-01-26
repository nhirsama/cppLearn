#define LOCAL
//P1510 精卫填海
//记得把文件重定向注释掉
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int v, n, c;

struct node {
    int a, b;
} arr[N];

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int sum = 0;
    cin >> v >> n >> c;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &arr[i].a, &arr[i].b);
        sum += arr[i].a;
    }
    if (sum - v < 0) {
        puts("Impossible");
        return 0;
    }
    vector<int> dp(sum - v + 10);
    for (int i = 0; i <= sum - v; i++) dp[i] = c;
    for (int i = 1; i <= n; i++) {
        for (int j = sum - v; j >= arr[i].a; j--) {
            dp[j] = min(dp[j - arr[i].a] - arr[i].b, dp[j]);
        }
    }
    if (dp[sum - v] > c || dp[sum - v] < 0) {
        puts("Impossible");
    } else cout << c - dp[sum - v] << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int v, n, c;
const int N = 1e4 + 10;
int dp[N];

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> v >> n >> c;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int j = c; j >= b; j--) {
            dp[j] = max(dp[j], dp[j - b] + a);
        }
    }
    int ans = -1;
    for (int i = 0; i <= c; i++) {
        if (dp[i] >= v) {
            ans = i;
            break;;
        }
    }
    if (ans == -1) puts("Impossible");
    else cout << c-ans << endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
