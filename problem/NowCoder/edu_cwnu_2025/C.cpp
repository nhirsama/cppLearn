#include <bits/stdc++.h>
using namespace std;
const int p = 1e9+7;
long long qpow(long long a,long long b) {
    long long ans = 1;
    a = (a % p + p) % p;
    for (; b; b >>= 1) {
        if (b & 1) ans = (a * ans) % p;
        a = (a * a) % p;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,a,b;
        cin>>n>>a>>b;
        long long an = qpow(2*a*b,n)%p;
        long long bn = qpow(10000,n*(p-2)%(p-1));
        cout<<an*bn%p<<endl;
    }
}