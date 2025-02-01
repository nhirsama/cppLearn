#define LOCAL
//P1455 搭配购买
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int root[N],n,m,w,dp[N],cnt,st[N];
pair<int,int> arr[N],sumArr[N];
int find(int x){
    return x==root[x]?x:root[x]=find(root[x]);
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&arr[i].first,&arr[i].second);
        root[i]=i;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        root[find(u)]=find(v);
    }
    for(int i=1;i<=n;i++){
        if(st[find(i)]){
            sumArr[st[find(i)]].first+=arr[i].first;
            sumArr[st[find(i)]].second+=arr[i].second;
        }
        else{
            st[find(i)]=++cnt;
            sumArr[st[find(i)]].first+=arr[i].first;
            sumArr[st[find(i)]].second+=arr[i].second;
        }
    }
    for(int i=1;i<=cnt;i++){
        for(int j=w;j>=sumArr[i].first;j--){
            dp[j]=max(dp[j],dp[j-sumArr[i].first]+sumArr[i].second);
        }
    }
    cout<<dp[w]<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}