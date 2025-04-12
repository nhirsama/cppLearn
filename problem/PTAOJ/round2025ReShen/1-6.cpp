#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<long long> num;
	int n;
	std::cin>>n;
	num.push_back(0);
	long long f = 0,b = 0;
	for(long long i = 1; i<=100000000; i++) {
		f+=i*i;
		if(i>n) {
			f-=(i-n)*(i-n);
			b+=(i-n)*(i-n);
		}
		if(i>2*n+1) {
			b-=(i-2*n-1)*(i-2*n-1);
		}
//		num.push_back(i*i);
//		num[i]+=num[i-1];
//		std::cout<<num[i]<< ' ';
		//if(i>=2*n+1 && num[i]-num[i-n] == num[i-n]-num[i-2*n-1]) {
		if(i>=2*n+1 && b == f) {
			for(int j = i-2*n; j<=i-n; j++) {
				std::cout<<j<<"^2";
				if(j!=i-n) {
					std::cout<<" + ";
				} else {
					std::cout<<" =\n";
				}
			}
			for(int j = i-n+1; j<=i; j++) {
				std::cout<<j<<"^2";
				if(j!=i) {
					std::cout<<" + ";
				}
			}
			return 0;
		}
	}

}
