
//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m;
ll phi(ll n){
    ll ans=n,m=sqrt(n);
    for(ll i=2;i<=m;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>m;
    cout<<phi(m);

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}