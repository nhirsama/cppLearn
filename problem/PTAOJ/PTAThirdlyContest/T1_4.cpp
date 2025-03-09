#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n,y,w,ans = 0;
    cin>>n>>y>>w;
    ans = (w+1)*w/2*n;
    cout<<max(0ll,ans-y)<<endl;

    return 0;
}