#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int arr[N], dj[N][N], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
        arr[i] += arr[i - 1];
    }

    for (int len = 2; len <= n; len++) {
        for (int j = 1; j + len-1 <= n; j++) {
            int l = j, r = j + len - 1;
            dj[l][r] = 0x3f3f3f3f;
            for (int k = l; k < r; k++) {
                dj[l][r] = min(dj[l][k] + dj[k + 1][r] + arr[r] - arr[l - 1], dj[l][r]);
            }
        }
    }
    cout << dj[1][n];
    return 0;
}
