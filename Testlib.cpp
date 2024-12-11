//luoguP3904
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=55;
int n,m;
string s[maxn][maxn];
string add(string a,string b)//高精度加法
{
    string ans;
    int l1=a.size(),l2=b.size();
    int lk=max(l1,l2);//选a和b里面长度最大的作为最终字符串长度
    int u[maxn*10]={0},v[maxn*10]={0};
    for(int i=0;i<l1;i++)u[l1-i-1]=a[i]-'0';
    for(int i=0;i<l2;i++)v[l2-i-1]=b[i]-'0';//字符串转数组
    for(int i=0;i<lk;i++)
    {
        u[i]+=v[i];
        u[i+1]+=u[i]/10;
        u[i]%=10;
    }//模拟加法运算
    if(u[lk])lk++;//当出现进位时，长度++
    for(int i=lk-1;i>=0;i--)ans+=u[i]+'0';//重新转成字符串
    return ans;
}
string mul(string a,int b)//高精a*单精b（大部分与加法相同，故不做注释）
{
    string ans;
    int l=a.size();
    int u[maxn*10]={0};
    for(int i=l-1;i>=0;i--)u[l-i-1]=a[i]-'0';
    int w=0;
    for(int i=0;i<l;i++)
    {
        u[i]=u[i]*b+w;
        w=u[i]/10;
        u[i]%=10;
    }
    while(w)u[l++]=w%10,w/=10;//注意这里与加法不同，是while循环而不是if特判，想一想为什么？
    for(int i=l-1;i>=0;i--)ans+=u[i]+'0';
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)s[i][1]="1";//初始化
    for(int i=1;i<=n;i++)
    {
        s[i][i]="1";
        for(int j=2;j<=m;j++)
        {
            s[i][j]=add(s[i-1][j-1],mul(s[i-1][j],j));//递推方程
        }
    }
    if(n<m)cout<<"0"<<endl;//注意特判
    else cout<<s[n][m]<<endl;
    return 0;
}
//6220194750