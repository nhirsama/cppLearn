//P8784 [蓝桥杯 2022 省 B] 积木画
//dp做法，可以优化为logn时间复杂度、空间复杂度为常数。
//并且未取模
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int dp[10000000][3];
int main() {
    int n;
    cin >> n;
    dp[0][0] = 1;
    dp[1][0] = 1;
    for(int i = 2;i<=n;i++){
        dp[i][0] = dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-2][0];
        dp[i][1] = dp[i-2][0]+dp[i-1][2];
        dp[i][2] = dp[i-2][0]+dp[i-1][1];
    }
    cout<<dp[n][0]<<endl;
    return 0;
}