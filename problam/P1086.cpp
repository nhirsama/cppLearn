//P1086 [NOIP2004 普及组] 花生采摘
#include <bits/stdc++.h>
using namespace std;
int M,N,K;
struct arr{
	int x;
	int y;
	int num;
};
vector <struct arr> sa;
bool sortCmp(struct arr a,struct arr b){
	return a.num>b.num;
}
int main(){
	cin>>M>>N>>K;
	for(int i = 1; i<=M;i++){
		for(int j =1;j<=N;j++){
			int m;
			cin >> m;
			if(m>0)sa.push_back({i,j,m});
		}
	}
	sort(sa.begin(),sa.end(),sortCmp);
	int ans = 0;
	int iMax = 0,iMay = sa[0].y;
	for(auto & i : sa){
		if(abs(iMax - i.x)+abs(iMay - i.y)+i.x+1<=K){
			ans+=i.num;
			K -= abs(iMax - i.x)+abs(iMay - i.y)+1;
			iMax = i.x;
			iMay = i.y;
		}
		else{break;}
	}
	cout<<ans;
	return 0;
}
