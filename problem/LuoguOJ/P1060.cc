//P1060 [NOIP 2006 普及组] 开心的金明
//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
#include <bits/stdc++.h>
using namespace std;
long long dp[30050], arr[35], w[35];

int main() {
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        long long v, p;
        cin >> v >> p;
        arr[i] = v * p;
        w[i] = v;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >=w[i]; j--) {
            dp[j] = max(dp[j],dp[j - w[i]] + arr[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}

//IMPORTANT!! Submit Code Region End(Do not remove this line)
