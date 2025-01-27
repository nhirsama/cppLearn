//5. 多重背包问题 II
//4. 多重背包问题 I

/*
//朴素多重背包
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n,v,vi[N],wi[N],si[N],dp[N][N];
int main(){
    cin>>n>>v;
    for(int i = 1;i<=n;i++){
        cin>>vi[i]>>wi[i]>>si[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=v;j++){
            for(int k = 0;k<=si[i] && k*vi[i]<=j;k++){
                dp[i][j] = max(dp[i][j],dp[i-1][j-k*vi[i]]+wi[i]*k);
            }
        }
    }
    cout<<dp[n][v];
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 2010,M = N*N*11;
int n,v,vi[N*12],wi[N*12],cnt;
int dp[M];
int main() {
    cin>>n>>v;
    for(int i=1;i<=n;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int j = 1;
        while (j<=c) {
            vi[++cnt] = j*a,wi[cnt] = j*b;
            c-=j;
            j<<=1;
        }
        if (c) {
            vi[++cnt] = c*a,wi[cnt] = c*b;
        }
    }
    for(int i=1;i<=cnt;i++) {
        for (int j=v;j>=vi[i];j--) {
            dp[j]=max(dp[j],dp[j-vi[i]]+wi[i]);
        }
    }
    cout<<dp[v]<<endl;
    return 0;
}