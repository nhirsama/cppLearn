#include <iostream>
#include <cmath>
using namespace std;
const int N=500010;
int days[N];
int cnt[N];
string s;
int n,sum,ans;
int main()
{
    cin>>n>>s;
    int x=0,num=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') num++,sum++;
        else if(s[i]=='0'&&i&&s[i-1]=='1')
        {
            cnt[x++]=num;
            num=0;
        }
    }
    if(num>0) cnt[x++]=num;
    // for(int i=0;i<x;i++) cout<<cnt[i]<<' ';
    // cout<<endl;
    if(x==1)//特判只有一段连续病牛
    {
        if(sum%2||s[0]=='1'||s[n-1]=='1') cout<<1<<endl;
        else cout<<2<<endl;
        return 0;
    }
    int day=1e9,j=0;
    for(int i=0;i<n;i++)//天数越大，初始的牛越少，找出可能的最大的天数
    {
        if(s[i]=='1')
        {
            if(i==0||i+cnt[j]==n) day=min(day,cnt[j]-1);
            else if(cnt[j]%2==1) day=min(day,cnt[j]/2);
            else if(cnt[j]%2==0) day=min(day,(cnt[j]-2)/2);
            i=i+cnt[j++]-1;
            // cout<<day<<' ';
        }
    }
    // cout<<endl;
    if(day==0)
    {
        cout<<sum<<endl;
        return 0;
    }

    for(int i=0;i<x;i++) //一头牛第i天能感染的牛的数量为i*2+1(包括自己)
    {
        if(cnt[i]%(day*2+1)==0) ans+=cnt[i]/(day*2+1);
        else ans+=(int)(cnt[i]*1.0/(day*2+1)+1);
    }
    cout<<ans<<endl;
    return 0;
}