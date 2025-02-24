//P9974 [USACO23DEC] Candy Cane Feast B
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, arr[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> arr[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y = 0;
        cin >> x;
        for (int k = 1; k <= n; k++) {
            if (x <= arr[k]) {
                arr[k] += x - y;
                break;
            } else if (y >= arr[k])continue;
            else {
                long long eat = arr[k] - y;
                y = arr[k];
                arr[k] += eat;
            }
        }
    }
    // while (!q.empty()) {
    //     auto z = q.front();
    //     q.pop();
    //     arr[z.second] = z.first;
    // }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}
