#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int N;
	vector<string> a;
	string st;
	while(cin>>st){
		a.push_back(st);
	}
	for(int i = a.size()-1;i>=0;i--){
		cout<<i;
		if(i != 0){
			cout<<' ';
		}
	}
	return 0;
}
