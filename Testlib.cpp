#include<vector>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
//不想打万能头文件
using namespace std;
typedef long long ll;
int n,b,tot,w,h[25],f[1000001];
int main()
{
	cin>>n>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		tot+=h[i];//求牛的总高度
	}
	w=tot-b;//w即为所以牛的高度减去书架的高度，也就是背包的容量
	for(int i=1;i<=n;i++)
	{
		for(int j=w;j>=h[i];j--)
		{
			f[j]=max(f[j],f[j-h[i]]+h[i]);//h[i]既相当于01背包里的容量又相当于价值
		}
	}
	cout<<tot-f[w]-b;//牛的总高度减去放入背包中牛的高度再减去书架高度就是所求解
	return 0;//结束
}