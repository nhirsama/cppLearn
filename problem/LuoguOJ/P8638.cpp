//#define LOCAL
//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    string s1,s2;
    cin>>s1;
    s2 = s1;
    reverse(s2.begin(),s2.end());
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            //if(i == 0 || j == 0) dp[i][j] = 0;
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<s1.size() - dp[s1.size()][s2.size()]<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}