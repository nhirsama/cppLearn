#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int check(int x)
{
	int t=1;//位数
	while(x)
	{
		if(x%10%2!=0&&t%2==0) return 0;//反过来思考
		if(x%10%2==0&&t%2!=0) return 0;
		x/=10;
		t++;
	}
	return 1;
}
int main()
{
	int count=0;
	int n=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if (check(i)==1) count++;
	}
	cout<<count<<endl;
	return 0;
}