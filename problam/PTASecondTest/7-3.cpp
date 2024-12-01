#include <bits/stdc++.h>
using namespace std;
int arr[1005];
bool st[1005];
int main(){
	int n;
	cin>>n;
	bool flag = true;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		if((flag&&arr[i]>n )||(flag && arr[i]<=0) || st[arr[i]])flag = false;
		st[arr[i]] = true;
	}
	if(flag){
		cout<<"YES";
	}
	else cout<<"NO";
	return 0;
}
