#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	std::cin>>n;
	vector<int> v(n);
	for(auto &i:v)std::cin>>i;
	vector<int> num;
	bool st[30] {0};
    long long allsum = 0;
	auto dfsinit = [&](auto && self,int nu,int p) {
		if(p == n) {
			num.push_back(nu);
            allsum+=nu*nu;
			return;
		}
		for(int i = 0; i<n; i++) {
			if(st[i]) continue;
			st[i] = 1;
			self(self,nu*10+v[i],p+1);
			st[i] =0;
		}
	};
	dfsinit(dfsinit,0,0);
	// for(auto i:num){
	//     std::cout<<i<< ' ';
	// }
	bool ok = false;
	auto dfs = [&](auto && self,long long sum,int p,int m) {
        if(sum>allsum/2) return;
		if(p == num.size()/2) {
            //std::cout<<sum<<endl;
			long long tsum = 0;
			for(int i  =0; i<num.size(); i++) {
				if(st[i] == 0) tsum+=num[i]*num[i];
			}
			if(tsum == sum) {
				ok = true;
				for(int i = 0; i<num.size(); i++) {
					if(st[i]) {
						std::cout<<num[i]<<'\n';
					}
				}
			}
			return;
		}
		if(ok)return;
		for(int i = m+1; i<num.size(); i++) {
			if(st[i]) {
				continue;
			}
			st[i] = 1;
			self(self,sum+num[i]*num[i],p+1,i);
			st[i] = 0;
		}
	};
    dfs(dfs,0,0,0);
}
