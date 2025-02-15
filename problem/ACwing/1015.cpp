#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int arr[N][N],dp[N][N];
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(arr,0,sizeof arr);
        memset(dp,0,sizeof dp);
        int r,c;
        cin>>r>>c;
        for(int i = 1;i<=r;i++){
            for(int j = 1;j<=c;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        for(int i  =  1;i<=r;i++){
            for(int j = 1;j<=c;j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])+arr[i][j];
            }
        }
        cout<<dp[r][c]<<endl;
    }
    return 0;
}