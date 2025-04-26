#include<bits/stdc++.h>
using i64 = long long int ;
int main(){
	for(int i = 1;i<1000;i++){
		std::cout<<"judging on test "<<i<<std::endl;
		std::system("testlib.exe > data.in");
		std::system("G2.exe < data.in > G.out");
		std::system("baoli.exe < data.in > baoli.out");
		if(std::system("fc G.out baoli.out")){
			std::cout<<"wrong answer on test" << i<<std::endl;
			return 0;
		}
	}
	std::cout<<"Accepted"<<std::endl;
	return 0;
}
