#define LOCAL
//P3985 不开心的金明
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int w,n,dp[N];
pair<int,int> v[105];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>w>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v+1,v+n+1);
    for(int i=1,j = 1;j<=n;){
        if(v[j].first-v[i].first>3){
            for(int k=N;k>=v[i].second;k--){
                dp[k]=max(dp[k],dp[k-v[i].second]+v[i].first);
            }
        }
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}