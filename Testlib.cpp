#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct uu{
    string name;
    int n;
    int c;
    char g;
    char k;
    int s;
    int yy;
    int ans;
}a[1001];
int t,kl;
bool cmp(uu x,uu y)
{
    if(x.ans==y.ans)return x.yy<y.yy;
    else return x.ans>y.ans;
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i].name>>a[i].n>>a[i].c>>a[i].g>>a[i].k>>a[i].s;
        a[i].yy=i;
    }
    for(int i=1;i<=t;i++){
        if(a[i].n>80&&a[i].s>=1)a[i].ans+=8000;
        if(a[i].n>85&&a[i].c>80)a[i].ans+=4000;
        if(a[i].n>90)a[i].ans+=2000;
        if(a[i].n>85&&a[i].k=='Y')a[i].ans+=1000;
        if(a[i].c>80&&a[i].g=='Y')a[i].ans+=850;
    }
    for(int i=1;i<=t;i++)kl+=a[i].ans;//统计
    sort(a+1,a+1+t,cmp);//排序
    cout<<a[1].name<<endl<<a[1].ans<<endl<<kl;
}