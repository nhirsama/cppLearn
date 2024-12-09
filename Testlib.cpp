#include<bits/stdc++.h>
using namespace std;

int P;
long long a[510];

long long POW2(int a)
{
    long long res=1;
    for(int i=1;i<=a;i++)
    {
        res*=2;
    }
    return res;
}

int main()
{
    cin>>P;

    cout<<ceil(P*log10(2))<<endl; // 第一问

    long long tmp=POW2(32);       // tmp=2^32

    a[500]=1;
    int t32=P/32;                 // t32：能乘以2^32的次数
    int t1=P-t32*32;              // t1： 剩下的，一个一个乘上去
    for(int T=1;T<=t32;T++)
    {
        for(int i=500;i>=1;i--)
        {
            a[i]*=tmp;            // 每一位都乘上2^32
        }
        for(int i=500;i>=1;i--)
        {
            a[i-1]+=a[i]/10;
            a[i]%=10;             // 处理进位
        }
    }
    for(int T=1;T<=t1;T++)
    {
        for(int i=500;i>=1;i--)
        {
            a[i]*=2;              // 每一位都乘上2
        }
        for(int i=500;i>=1;i--)
        {
            a[i-1]+=a[i]/10;
            a[i]%=10;             // 处理进位
        }
    }
    a[500]--;

    for(int i=1;i<=500;i++)
    {
        cout<<a[i];
        if(i%50==0) cout<<endl;
    }

    return 0;
}