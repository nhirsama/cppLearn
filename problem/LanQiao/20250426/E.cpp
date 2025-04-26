#include<bits/stdc++.h>
using i64 = long long int ;
int main(){
	i64 n;
	std::cin>>n;
	std::vector<int> a(n),b(n);
	for(int i = 0;i<n;i++){
		std::cin>>a[i];
	}
	std::priority_queue<int> pq;
	for(int i = 0;i<n;i++){
		std::cin>>b[i];
		pq.push(b[i]);
	}
	std::sort(a.begin(),a.end());
	
	i64 ans = 0;
	for(int i = n-1;~i;i--){
		if(a[i]>pq.top()){
			pq.pop();
		}
		else {
			ans++;
			pq.pop();
			pq.push(-1e9-1);
			i++;
		}
	}
	std::cout<<ans<<std::endl;
	return 0;
}
/*
4
22 31 12 14
3 19 27 44
*/
