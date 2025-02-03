#define LOCAL
//P2758 编辑距离
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
string a,b;
int dp[N][N];
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
    #endif
    cin>>a>>b;
    for(int i=1;i<=a.length();i++) dp[i][0]=i;
    for(int i=1;i<=b.length();i++) dp[0][i]=i;
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            dp[i][j]=min(dp[i-1][j-1]+(a[i-1] != b[j-1]),min(dp[i-1][j],dp[i][j-1])+1);
        }
    }
    cout<<dp[a.length()][b.length()]<<endl;
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
