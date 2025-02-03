#define LOCAL
//P1279 字串距离
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
string A,B;
int dp[2005][2005],k;
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
    #endif
    cin>>A>>B>>k;
    for(int i=0;i<=A.length();i++) dp[i][0]=k*i;
    for(int i=0;i<=B.length();i++) dp[0][i]=k*i;
    for(int i=1;i<=A.length();i++){
        for(int j=1;j<=B.length();j++){
            dp[i][j] = min(dp[i-1][j-1]+abs(A[i-1]-B[j-1]),min(dp[i-1][j],dp[i][j-1])+k);
        }
    }
    cout<<dp[A.length()][B.length()]<<endl;
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
