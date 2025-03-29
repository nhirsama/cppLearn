#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;
using pii = pair<i32,i32> ;
int main() {
	string s;
	cin>>s;
	queue <char> yy,fy;
	for(char i:s) {
		if(i == 'A' ||i == 'E'||i == 'I'||  i == 'O' || i == 'U' ) {
			yy.push(i);
		} else {
			fy.push(i);
		}
	}
	string ans;
	while(yy.size() && fy.size()) {
		if(yy.front()<fy.front()) {
			ans.push_back(yy.front());
			yy.pop();
		} else {
			ans.push_back(fy.front());
			fy.pop();
		}
	}
	while(yy.size()) {
		ans.push_back(yy.front());
		yy.pop();
	}
	while(fy.size()) {
		ans.push_back(fy.front());
		fy.pop();
	}
	cout<<ans<<endl;
	return 0;
}
