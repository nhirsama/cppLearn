//P9741 「KDOI-06-J」翻转与反转
#include <bits/stdc++.h>
using namespace std;
bool arr[2000005];
int main(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		int a;
		cin>>a;
		arr[i] = a;
	}
	if(n & 1){
		for(int i = n;i>0;i-=2){
			if((n-i+1)&1){
				cout<<!arr[i]<<' ';
			}
			else {
				cout <<arr[i]<<' ';
			}
		}
		for(int i = 2;i<=n;i+=2){
			if((n-i+1)&1){
				cout<<!arr[i]<<' ';
			}
			else {
				cout <<arr[i]<<' ';
			}
		}
	}
	else{
		for(int i = n;i>0;i-=2){
			cout<<!arr[i]<<' ';
		}
		for(int i = 1;i<=n;i+=2){
			cout <<arr[i]<<' ';
		}
	}
	return 0;
}
