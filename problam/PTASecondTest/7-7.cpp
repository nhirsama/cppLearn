#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int m = log2(n);
	int aa = pow(2,m-1);
	if(n %2 == 1){
		n--;
	}
	if(n == 0){
		cout<<1;
		return 0;
	}
	for(int i = n;i>1;i-=2){
		if(i%aa == 0){
			cout<<i;
			break;
		}
	}
	return 0;
}
