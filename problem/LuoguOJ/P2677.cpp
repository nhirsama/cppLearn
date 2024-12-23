#define LOCAL
//P2677 [USACO07DEC] Bookshelf 2 B
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int n,sum,m,arr[25],dp[2000005];
void dpFunc(){
    for(int i=1;i<=n;i++){
        for(int j = sum;j>=arr[i];j--){
            dp[j]=max(dp[j],dp[j-arr[i]]+arr[i]);
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        arr[i]=x;
        sum+=x;
    }
    sum = sum-m;
    dpFunc();
    cout<<sum-dp[sum]<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}