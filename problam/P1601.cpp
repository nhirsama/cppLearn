#include <bits/stdc++.h>
using namespace std;
vector <char> a;
vector <char> b;
vector <char> add(vector <char> &aa,vector <char> &bb){
	if(aa.size()<bb.size())return add(bb,aa);
	for(int i=  0;i<aa.size();i++){
		if(i<bb.size())aa[i] += bb[i];
		if(aa[i]>=10){
			if (i == aa.size()-1)aa.push_back(1);
			else aa[i+1]++;
			aa[i] %=10;
		}
	}
	return aa;
}
vector <char> mul(vector <char> &aa,vector <char> &bb){
	if(aa.size()<bb.size())return mul(bb,aa);
	vector<char> c(aa.size()+bb.size()+1,0);
	for(int i = 0;i<aa.size();i++){
		for(int j = 0;j<bb.size();j++){
			c[i+j] += a[i]*b[j];
			c[i+j+1] += c[i+j]/10;
			c[i+j] %= 10;
		}
	}
	while(c.size()>1 && c.back() == 0)c.pop_back();
	return c;
}
int main(){
	string mm;
	string bb;
	cin>>mm>>bb;
	for(int i = mm.size()-1;i>=0;i--){
		a.push_back(mm[i]-'0');
	}
	for(int i = bb.size()-1;i>=0;i--){
		b.push_back(bb[i]-'0');
	}
	a = mul(a,b);
	for (int i = a.size()-1 ; i >= 0; i--) {
		cout<<(char)(a[i]+'0');
	}
	return 0;
}
