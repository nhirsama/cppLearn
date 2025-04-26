#include<bits/stdc++.h>
using i64 = long long int ;
int main(){
	i64 h,w;
	std::cin>>h>>w;
	std::string base = "LANQIAO";
	i64 ans = 0;
	for(int i = 0;i<h;i++){
		for(int j = 0;j<w;j++){
			if(base[(i+j)%7] == 'A') ans++;
		}
	}
	std::cout<<ans<<std::endl;
	return 0;
}
