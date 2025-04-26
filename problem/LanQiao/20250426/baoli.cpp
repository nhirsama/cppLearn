#include<bits/stdc++.h>
using i64 = long long int ;
int dp[2000][2]; //
int main() {
	int n,m;
	std::cin>>n>>m;

	std::vector<std::string> g(n);
	for(int i = 0; i<n; i++) {
		std::cin>>g[i];
	}
	i64 ans[4][2]{};
	for(int i = 0; i<n; i++) {
		int sum = 0;
		for(int j = 0; j<m; j++) {
			int cnt000 = 0,cnt010 = 0,cnt110 = 0,cnt100 = 0;
			if(i>0) if(g[i-1][j] == g[i][j]) cnt000++;
			if(i<n-1) if(g[i+1][j] == g[i][j]) cnt000++;
			if(j>0) if(g[i][j-1] == g[i][j]) cnt000++;
			if(j<m-1) if(g[i][j+1] == g[i][j]) cnt000++;
			
			if(i>0) if(g[i-1][j] != g[i][j]) cnt100++;
			if(i<n-1) if(g[i+1][j] == g[i][j]) cnt100++;
			if(j>0) if(g[i][j-1] == g[i][j]) cnt100++;
			if(j<m-1) if(g[i][j+1] == g[i][j]) cnt100++;
			
			if(i>0) if(g[i-1][j] == g[i][j]) cnt110++;
			if(i<n-1) if(g[i+1][j] != g[i][j]) cnt110++;
			if(j>0) if(g[i][j-1] == g[i][j]) cnt110++;
			if(j<m-1) if(g[i][j+1] == g[i][j]) cnt110++;
			
			if(i>0) if(g[i-1][j] != g[i][j]) cnt010++;
			if(i<n-1) if(g[i+1][j] != g[i][j]) cnt010++;
			if(j>0) if(g[i][j-1] == g[i][j]) cnt010++;
			if(j<m-1) if(g[i][j+1] == g[i][j]) cnt010++;
			ans[0][1] = ans[0][0]+cnt000*cnt000;
			ans[2][1] = ans[3][0]+cnt010*cnt010;
			ans[1][1] = 
			
			ans+=std::max(std::max(cnt000*cnt000,cnt100*cnt100),std::max(cnt010*cnt010,cnt110*cnt110));
		}
	}
	std::cout<<ans;
	return 0;
}
/*
4 4
1010
1111
1011
1100
 */
