#include<bits/stdc++.h>
using i64 = long long int ;
int main(){
	for(int i = 1;i<1000;i++){
		std::cout<<"juding on test "<<i<<std::endl;
		std::system("testlib.exe > data.in");
		std::system("E.exe < data.in > E.out");
		std::system("E.exe < data.in > baoli.out");
		if(std::system("fc E.out baoli.out")){
			std::cout<<"wrong answer on test" << i<<std::endl;
			return 0;
		}
	}
	std::cout<<"Accepted"<<std::endl;
	return 0;
}
