//P1077 [NOIP 2012 普及组] 摆花
#include <bits/stdc++.h>
using namespace std;
int n,m,arr[105];
constexpr int mod = 1e6+7;
int dp[105][105];
int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>arr[i];
    dp[0][0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=m;j++){
            for(int k = 0;k<=min(j,arr[i]);k++){
                dp[i][j] += dp[i-1][j-k];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[n][m];
}