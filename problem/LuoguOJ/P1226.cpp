//P1226 【模板】快速幂
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,p;
    cin>>a>>b>>p;
    long long b2 = b;
    long long ans = 1;
    long long powVel = a;
    while(b>0){

        if(b&1){
            ans*=powVel;
            ans%=p;
        }
        powVel *= powVel;
        powVel %= p;
        b>>=1;
    }
    cout<<a<<'^'<<b2<<" mod "<<p<<'='<<ans;
    return 0;
}