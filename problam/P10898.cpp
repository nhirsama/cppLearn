#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a = 7385137888721;
	long long b = 10470245;
	a = (long long)sqrt(a)*2;
	while(a*4+4<=b){
		a+=2;
		b-=a*4+4;
	}
	cout << a;
	return 0;
}
