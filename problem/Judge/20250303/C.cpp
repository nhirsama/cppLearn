#include <bits/stdc++.h>
using namespace std;
int main() {
    long long m;
    cin >> m;
    // m*2+i*i+i+j =j*j
    for(long long i = 1;i < m;i++){
      long long j = sqrt(m*2+i*i-i);
        if (i>j)continue;
        if(m*2+i*i-i==j*(j+1)){
            cout<<i<<" "<<j<<endl;
        }
        else if (m*2+i*i-i==(j-1)*j) {
            cout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}