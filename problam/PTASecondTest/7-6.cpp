#include <bits/stdc++.h>
using namespace std;
int arr[500005][2];
int main(){
	int n;
	cin>>n;
	int ans = 12312312;
	for(int i =1;i<=n;i++){
		cin>>arr[i][0]>>arr[i][1];
		if(ans>min(arr[i][0],arr[i][1]))ans = min(arr[i][0],arr[i][1]);
		for(int j = ans;j>1;j--){
			if(arr[i][0]%(ans/j) == 0 && arr[i][1]%(ans/j) == 0){
				if(ans>j) ans = ans/j;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		cout<<arr[i][0]/ans<< ' ' <<arr[i][1]/ans<<'\n';
	}
	return 0;
}
