#include <bits/stdc++.h>
using  namespace std;
int n,m;
int arr[2005][2005];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i =1;i<=m;i++){
		int x1,x2,x3,x4;
		cin>>x1>>x2>>x3>>x4;
		for(int j = x1;j<=x3;i++){
			for(int k = x2;k<=x4;k++){
				arr[j][k]++;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(arr[i][j] & 1)cout<<1;
			else cout<<0;
		}
		cout<<'\n';
	}
	return 0;
}
