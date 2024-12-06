#include <bits/stdc++.h>
using namespace std;
const int modNum = 1e9+7;
long long quik_power(int a,int b){
    long long base = a;
    while(b>0){
        long long c = 1;

        if(b & 1){
            c *= base;
            c %= modNum;
        }
        b = b >> 1;
        base*=base;
        base %= modNum;
    }
    return base;
}
int main()
{
    int bl[7];
    // 请在此输入您的代码
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        bl[a]++;
        bl[b]++;
    }
    long long aaa = quik_power(4,n)*quik_power(6,n)%modNum;
    cout << aaa;
    return 0;
}