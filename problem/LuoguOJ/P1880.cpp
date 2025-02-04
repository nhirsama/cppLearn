#define LOCAL
//P1880 [NOI1995] 石子合并
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dp1[N*2][N*2], arr[N*2], dp2[N*2][N*2],n;
int main() {
    #ifdef LOCAL
    freopen("inAndoutFile/P1880_2.in", "r", stdin);
    freopen("Code.out", "w", stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        arr[i+n]=arr[i];
    }
    for(int i=1;i<=2*n;i++){
        arr[i]+=arr[i-1];
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=2*n;i++){
            int l=i,r=i+len-1;
            dp1[l][r]=0x3f3f3f3f;
            for(int k=l;k<r;k++){
                dp1[l][r]=min(dp1[l][r],dp1[l][k]+dp1[k+1][r]+arr[r]-arr[l-1]);
                //复制dp1的代码没改全,有一个是dp2＋dp1,害我改了半天
                dp2[l][r]=max(dp2[l][r],dp2[l][k]+dp2[k+1][r]+arr[r]-arr[l-1]);
            }
        }
    }
    int ans1=0x3f3f3f3f,ans2=0;
    for(int i=1;i<=n;i++){
        ans1=min(ans1,dp1[i][i+n-1]);
        ans2=max(ans2,dp2[i][i+n-1]);
    }
    cout<<ans1<<"\n"<<ans2<<endl;
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
