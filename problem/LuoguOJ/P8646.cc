//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N * N];

int main() {
    int n;
    cin >> n;
    vector arr(n + 1, 0);
    int gcdd = 200;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (gcdd == 200) gcdd = arr[i];
        else gcdd = gcd(gcdd, arr[i]);
    }
    if (gcdd == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = arr[i]; j <= 10000; j++) {
                dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
            }
        }
        int cnt = 0;
        for (int i = 1; i <= 10000; i++) {
            if (dp[i] != i) cnt++;
        }
        cout << cnt << endl;
    } else cout << "INF" << endl;

    return 0;
}

//IMPORTANT!! Submit Code Region End(Do not remove this line)
