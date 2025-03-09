#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
const int mod = 1e9 + 7;
ll arr[N][N], base[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> base[i][j];
        }
    }
    memset(arr, 0, sizeof(arr));
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        arr[x1][y1] += c;
        arr[x1][y2 + 1] -= c;
        arr[x2 + 1][y1] -= c;
        arr[x2 + 1][y2 + 1] += c;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j > 1) arr[i][j] += arr[i][j - 1];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) arr[i][j] += arr[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = (base[i][j] + arr[i][j]) % mod;
            arr[i][j] = arr[i][j] * arr[i][j] % mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = (arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]) % mod;
            arr[i][j] = (arr[i][j] + mod) % mod;
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = (arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1]) % mod;
        ans = (ans + mod) % mod;
        cout << ans << '\n';
    }
    return 0;
}