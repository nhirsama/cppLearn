#include<bits/stdc++.h>
using i64 = long long int ;
int main(){
	i64 n;
	std::cin>>n;
	i64 ans = 0;
	for(int i = 0;i<25;i++){
		ans+=n+i;
	}
	std::cout<<ans<<std::endl;
	return 0;
}
