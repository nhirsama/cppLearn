#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	std::cin>>n>>m;
	vector<string> vs;
	string base1 = "qiandao",base2 = "easy";
	for(int i = 0; i<n; i++) {
		string s;
		getline(cin,s);
		bool ok = false;
		for(int j = 0; j<s.size(); j++) {
			if(s.substr(j,7) == base1) {
				ok = true;
				break;
			}
			if(s.substr(j,4) == base2) {
				ok = true;
				break;
			}
		}
		if(ok) continue;
		vs.push_back(s);
	}
//	for(auto i:vs){
//		std::cout<<i<<std::endl;
//	}
	if(vs.size()<=m){
		std::cout<<"Wo AK le"<<std::endl;
	}
	else {
		std::cout<<vs[m+1]<<std::endl;
	}
}
