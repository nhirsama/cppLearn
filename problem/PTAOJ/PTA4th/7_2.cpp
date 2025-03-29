#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;
using pii = pair<i32,i32> ;
int main(){
    ios::sync_with_stdio(false);
	i32 n;
    cin>>n;
    vector<i64> w(n+1);
    vector g(n+1,vector<i32>());
    for(i32 i = 1;i<=n;i++){
        cin>>w[i];
    }
    for(i32 i = 2;i<=n;i++){
        i32 u;
        cin>>u;
        g[u].push_back(i);
    }
    i64 ans = w[1];
    auto dfs = [&](auto && self,i32 u)->i64{
        if(g[u].size() == 0) return w[u];
        i64 sum = -1;
        for(i32 v : g[u]){
            if(sum == -1){
                sum = self(self,v);
            }
            else sum = min(sum,self(self,v));
            //sum = max(sum,(w[u]+self(self,v))/2);
        }
        sum = min(sum,w[u]+sum/2);
        return sum;
    };
    i64 minn = 0x3f3f3f3f3f3f3f3f;
    for(i32 i: g[1]){
        //cout<<i<<endl;
        i64 t = dfs(dfs,i);
        //cout<<t<<endl;
        minn = min(minn,t);
        //cout<<dfs(dfs,i)<<endl;
    }
    ans += minn;
    cout<<ans<<endl;
	return 0;
}
