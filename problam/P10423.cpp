//P10423 [¿∂«≈±≠ 2024  ° B] ÃÓø’Œ Ã‚
#include <bits/stdc++.h>
using namespace std;
int main(){
	double ans[2];
	ans[0] = 43*42/2+7*43;
	long long chang = 343720*2;
	long long kuan = 233333*2;
	int m = 1059;
	int n = 1768;
	ans[1] = sqrt(chang*m*chang*m+kuan*n*kuan*n);
	//cout<<ans[1];
//	for(int i = 1;i<=10000;i++){
//		for(int j = 1;j<=10000;j++){
//			if(i*chang*17 == j*kuan*15)cout<<i<< ' ' <<j<<'\n';
//		}
//	}
	for(int i = 0;i<=1;i++){
	    char T;
	    cin >> T;
	    if(T == 'A')cout<<ans[0]<<endl;
	    if(T == 'B')printf("%.2f",&ans[1]);
	}
	return 0;
}
