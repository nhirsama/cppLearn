#include <bits/stdc++.h>
using namespace std;
int Func(){
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 0;i<=n;i++){
		//for(int j = (int)sqrt(n*n-i*i);j*j<n*n+2*n+1+i*i;j++){
		for(int j = 0;j<=n;j++){
			if(n == (int)sqrt(i*i+j*j))ans++;
		}
	}
	return ans;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cout<<4*Func()<<endl;
	}
	return 0;
}
