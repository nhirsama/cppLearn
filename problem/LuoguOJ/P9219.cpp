//P9219 「TAOI-1」Antipathy World
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
void solve() {
    ll n,k;
    cin>>n>>k;
    pair<ll,ll> ans;
    ll maxn=0;
    for(ll i=1;i<n;i+=2) {
        cout<<"? "<<i<<" "<<i+1<<endl;
        ll a;
        cin>>a;
        if(a>maxn) {
            ans = {i,i+1};
            maxn=a;
        }
    }
    if(n&1){
        cout<<"? "<<ans.first<<" "<<n<<endl;
        ll a,b;
        cin>>a;
        cout<<"? "<<ans.second<<" "<<n<<endl;
        cin>>b;
        if (a>maxn && b>maxn) {
            cout<<"! "<<n<<endl;
        }
        else if(a>b) {
            cout<<"! "<<ans.first<<endl;
        }
        else  {
            cout<<"! "<<ans.second<<endl;
        }
    }
    else {
        ll m = ans.second<n?n:1;
        cout<<"? "<<ans.first<<" "<<m<<endl;
        ll a,b;
        cin>>a;
        cout<<"? "<<ans.second<<" "<<m<<endl;
        cin>>b;
        if(a>b) {
            cout<<"! "<<ans.first<<endl;
        }
        else  {
            cout<<"! "<<ans.second<<endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
