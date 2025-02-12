#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
#define first x;
#define second y;
ll n,arr[N];
int num[N];
int dp[N];
int main() {
    cin>>n;
    int ans = 0;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=arr[i];j++) {
            dp[j] = dp[j]+j;
            ans = max(ans,dp[j]);
        }
        for(int j=arr[i]+1;j<N;j++) {
            dp[j] = 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
