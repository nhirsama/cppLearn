#include <bits/stdc++.h>
using namespace std;
void Func(){
	string s;
	int m,k;
	cin>>s>>m>>k;
	int le = s.size()/m;
	int yv = s.size()%m;
	while(k--){
		string temp;
		for(int i =0;i<le;i++){
			for(int j = 0;j<m;j++){
				if(j<yv){
					if(j*(le+1)+i >= s.size())continue;
					temp.push_back(s[j*(le+1)+i]);
				}
				else{
					if(j*le+i+yv >= s.size())continue;
					temp.push_back(s[j*le+i+yv]);
				}
			}
		}
		for(int i =1;i<=yv;i++){
			temp.push_back(s[le*i]);
		}
		s = temp;
	}
	cout<<s<<endl;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		Func();
	}
	return 0;
}
