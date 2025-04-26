#include<bits/stdc++.h>
using i64 = long long int ;
int main() {
	i64 ans = 0;
	for(int i = 1;10*i+45<=20255202;i++){
		int t = 10*i+45;
		int en = t%10,tt = t;
		bool flag = true;
		while(tt){
			if(tt%10 != en) {
				flag = false;
				break;
			}
			tt/=10;
		}
		if(!flag)continue;
		std::cout<<t<<std::endl;
		ans+=t;
	}
	std::cout<<ans<<std::endl;
	return 0;
}
// ans = 6172830;
