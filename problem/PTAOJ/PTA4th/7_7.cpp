#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;
using pii = pair<i32,i32> ;
void nhir(){
    i64 x,y;
    i64 n,sum = 0;
    cin>>n;
    cin>>x>>y;
    vector<i64> v(n+1);
    for(i32 i = 1;i<=n;i++){
        cin>>v[i];
        sum+=v[i];
        }
    i32 ans = 0;
    i64 upp = sum-x,loww = sum-y;
    // for(i32 i = 1;i<=n;i++){
    //     for(i32 j = i+1;j<=n;j++){
    //         if(loww<=v[i]+v[j] && v[i]+v[j]<=upp) ans++;
    //     }
    // }
    // cout<<ans<<endl;
    sort(v.begin()+1,v.end());
    for(i32 i = 1;i<=n;i++){
        i32 pu = lower_bound(v.begin()+i+1,v.end(),upp-v[i]+1)-v.begin();
       // if(pu == n+1) continue;
        i32 pl = lower_bound(v.begin()+1+i,v.end(),loww-v[i])-v.begin();
        //if(pl == n+1) continue;
        ans+=pu-pl;
       // cout<<pu<< ' ' <<pl<<endl;
        //if(pl<= i && i<pu) ans--;
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
    i32 t;
    cin>>t;
    while(t--)nhir();
	return 0;
}
