//P4170 [CQOI2007] 涂色
#include <bits/stdc++.h>
using namespace std;
int n = INT_MAX;
string s;
int n,dp[55][55];
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin>>s;
    n=s.length();
    s="#"+s;
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=n;i++) dp[i][i] = 1;
    for(int len = 2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int l = i,r = i+len-1;
            for(int j=l;j<r;j++){
                if(s[l] == s[r] || s[l] == s[j+1] || s[j] == s[j+1] || s[j]  == s[r])dp[l][r] = min(dp[l][r],dp[l][j]+dp[j+1][r]-1);
                else dp[l][r] = min(dp[l][r],dp[l][j]+dp[j+1][r]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
