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
    int t = 1;
    while(t--){
        long long m,n;
        cin>>m>>n;
        long long ans = qpow(m,n%(p-1));
        cout<<(ans-m+p)%p<<endl;
    }
}