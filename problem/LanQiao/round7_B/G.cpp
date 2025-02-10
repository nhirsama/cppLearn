#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
ll n;
ll arr[N];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
    }
    sort(arr+1,arr+n+1);
    n = unique(arr+1,arr+n+1)-arr-1;
    ll a = 100000000000000,b = 1;
    for(int i=1;i<n;i++) {
        if ((double)arr[i+1]/arr[i] < double(a)/b) {
            ll gg = gcd(arr[i],arr[i+1]);
            a = arr[i+1]/gg;
            b = arr[i]/gg;
        }
    }
    cout<<a<<"/"<<b<<endl;
    return 0;
}
