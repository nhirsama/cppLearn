#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int ans,ma,c[100005],b[100005],r[100005];
int fen(int x)//二分
{
	int le=0,ri=ma,mid;
	while(le<ri)
	{
		mid=(le+ri)/2+1;
		if(r[mid]>=x) ri=mid-1;
		else le=mid;
	}
	return le;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],c[a[i]]=i;//如果直接二重循环枚举的话肯定会超时的，所以借助一个c[]暂时存储c[i]的标号（a[i]的编号就是i）
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		b[i]=c[x];
	}
	for(int i=1;i<=n;i++)
	{
		int l=fen(b[i])+1;
		ans=max(ans,l);
		r[l]=(!r[l]?b[i]:min(r[l],b[i]));
		ma=max(ma,l);
	}//最长上升子序列
	cout<<ans;
	return 0;
}