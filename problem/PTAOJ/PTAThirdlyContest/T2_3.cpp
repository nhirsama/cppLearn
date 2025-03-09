#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
const int mod = 1e9 + 7;
long long arr[N][N], base[N][N];

int main() {
    ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> base[i][j];
        }
    }
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        arr[x1][y1] += c;
        arr[x1][y2 + 1] -= c;
        arr[x2 + 1][y1] -= c;
        arr[x2 + 1][y2 + 1] += c;
    }
    cin >> q;
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
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         arr[i][j] += base[i][j];
    //         arr[i][j] = (arr[i][j]+mod)%mod;
    //         arr[i][j] = arr[i][j] * arr[i][j] % mod;
    //     }
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = (arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + mod) % mod;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         arr[i][j] = (arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]) % mod;
    //         arr[i][j] = (arr[i][j] + mod) % mod;
    //     }
    // }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (arr[x2][y2] + arr[x1 - 1][y1 - 1] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + mod) % mod << endl;
    }
    return 0;
}
