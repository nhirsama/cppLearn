#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
int main() {
    ll n;
    cin>>n;
    vector<ll> ans;
    ll arr[5];
    while(arr[1]*arr[1]+arr[2]*arr[2]+arr[3]*arr[3]+arr[4]*arr[4] != n){
        sort(arr+1,arr+5);
        arr[1]++;
    }
    sort(arr+1,arr+5);
    cout<<arr[1]<<' '<<arr[2]<<' '<<arr[3]<<' '<<arr[4]<<endl;
    return 0;
}
