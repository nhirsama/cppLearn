//P11671 [USACO25JAN] Farmer John's Favorite Operation S
#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
long long arr[N], n, m, sum[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", arr + i);
            arr[i] %= m;
        }
        sort(arr + 1, arr + n + 1);
        for (int i = 1; i <= n; i++)arr[n + i] = arr[i] + m;
        for (int i = 1; i <= 2 * n; i++)sum[i] = arr[i] + sum[i - 1];
        long long ans = 0x3f3f3f3f3f3f3f3f;
        int x = n / 2 + (n & 1);
        for (int i = 0; i < n; i++) {
            int mid = x + i;
            long long f = arr[mid] * (mid - i - 1) - (sum[mid - 1] - sum[i]);
            long long b = (sum[n + i] - sum[mid]) - arr[mid] * (n + i - mid);
            ans = min(ans, f + b);
        }
        cout << ans << endl;
    }
    return 0;
}
