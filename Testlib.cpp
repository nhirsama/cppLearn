//P4231 三步必杀
#include <bits/stdc++.h>
using namespace std;
int arr[10000005];
int arr1[10000005];
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	while(m--) {
		long long l,r,s,e;
		scanf("%lld %lld %lld %lld",&l,&r,&s,&e);
		int q = (e-s)/(r-l);
		arr[l]+=s;
		arr[r+1]-=e;
		arr1[l+1]+=q;
		arr1[r+1]-=q;
	}
	long long xorAns = 0,sum = 0,cF = 0,maxNum = 0;
	for (int i = 1; i <= n; i++) {
		cF += arr1[i];
		sum += cF + arr[i];
		xorAns ^= sum;
		if (sum > maxNum) {
			maxNum = sum;
		}
	}
	printf("%lld %lld\n",xorAns,maxNum);
	return 0;
}