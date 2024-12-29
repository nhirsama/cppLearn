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
	return 0;
}