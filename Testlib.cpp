#include <iostream>

using namespace std;

long long i,j,k,n,m,p,q;
unsigned long long c,d,nextc,nextd;
unsigned long long a[30005];

int main(void) {
    cin>>p>>q>>a[1]>>a[2]>>n>>m;
    p%=m;
    q%=m;
    a[1]%=m;
    a[2]%=m;
    a[3]=(p*a[2]+q*a[1])%m;
    nextc=p;
    nextd=q;
    for(i=2; i<=29999; i++) {
        c=(p*nextc+nextd)%m;
        d=(q*nextc)%m;
        nextc=c;
        nextd=d;
    }
    while(n>30000) {
        n-=30000;
        a[1]=(nextc*a[2]+nextd*a[1])%m;
        a[2]=(nextc*a[3]+nextd*a[2])%m;
        a[3]=(p*a[2]+q*a[1])%m;
    }
    for(i=4; i<=n; i++) {
        a[i]=(p*a[i-1]+q*a[i-2])%m;
    }
    cout<<a[n]<<endl;
    return 0;
}