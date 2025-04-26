#include<bits/stdc++.h>
using i64 = long long int ;
int main(){
	std::random_device rd;
	std::mt19937 mt(rd());
	int m = mt()%(1007),n = mt()%(1007);
//	std::cout<<m<< ' '<<n<<std::endl;
//	for(int i = 0;i<m;i++){
//		std::cout<<mt()%(1000000001)<< ' ';
//	}
//	std::cout<<std::endl;
//	for(int i = 0;i<n;i++){
//		std::cout<<mt()%(1000000001)<< ' ';
//	}
	std::cout<<n<< ' '<<m<<std::endl;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			std::cout<<mt()%2;
		}
		std::cout<<std::endl;
	}
	//std::cout<<mt()<<std::endl;
	return 0;
}
