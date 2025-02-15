#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector dp(n,vector<int>(2));
        vector<int> arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        dp[0][1] = arr[0];
        for(int i = 1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0]+arr[i];
        }
        cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
    }
    return 0;
}