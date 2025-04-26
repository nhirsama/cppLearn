#include<bits/stdc++.h>
using i64 = long long int ;
int main(){
	i64 h,w;
	std::cin>>h>>w;
	std::string base = "LANQIAO";
	std::string sss;
	for(int i = 0;i<=(w/7+1)*h;i++){
		sss+=base;
	}
//	sss = sss.substr(0,w);
	i64 ans = 0;
	for(int i = 0;i<h;i++){
		for(int j = 0;j<w;j++){
			if(sss[j+i] == 'A') ans++;
		}
//		std::cout<<sss<<std::endl;
//		sss = sss.substr(1)+sss[0];
		
	}
	std::cout<<ans<<std::endl;
	return 0;
}
