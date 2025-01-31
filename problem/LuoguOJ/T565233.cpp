#define LOCAL
//T565233 【MX-X8-T1】「TAOI-3」幸运草
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int x,arr[N],n;
long long sum,dp[N],sum1;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>x;
    for(int i=1;i<=n;i++){
      cin>>arr[i];
      sum+=arr[i];
      arr[i]=x-arr[i];
    }
    for(int i=1;i<=n;i++) {
        dp[i]=max(1ll*arr[i],dp[i-1]+arr[i]);
    }
    for(int i=1;i<=n;i++) {
        sum1=max(sum1,dp[i]);
    }
    cout<<sum+sum1<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
