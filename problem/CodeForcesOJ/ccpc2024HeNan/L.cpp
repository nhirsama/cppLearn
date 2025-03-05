// wa6
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main() {
    int n,m;
    cin >> n >> m;
    ll ans = 0;
    vector<ll> arr(m+1);
    for(int i = 1;i<=m;i++)cin>>arr[i];
    ll x = 1;
    for(int i = 2;i<=m;i++){
        if ((x+1)*(x+1)*(x+1)*(x+1)+arr[i]) {
            x++;
        }
        else {
            ans+=arr[i-1]+x*x*x*x;
            x = 1;
        }
        // if(arr[i]>x*(x*(4*x+6)+4)+1) x++;
        // else {
        //     ans+=arr[i-1]+x*x*x*x;
        //     x = 1;
        // }
    }
    ans+=arr[m]+x*x*x*x;
    cout<<ans<<endl;
    return 0;
}
