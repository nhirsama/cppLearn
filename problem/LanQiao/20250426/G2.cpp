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
	for(int i = 0; i<n; i++) {
		int sum = 0;
		for(int j = 0; j<m; j++) {
			int cnt = 0;
			if(i>0) if(g[i-1][j] == g[i][j]) cnt++;
			if(i<n-1) if(g[i+1][j] == g[i][j]) cnt++;
			if(j>0) if(g[i][j-1] == g[i][j]) cnt++;
			if(j<m-1) if(g[i][j+1] == g[i][j]) cnt++;
			sum +=cnt*cnt;
		}
		if(i) dp[i][0] = dp[i-1][0]+sum;
		else dp[i][0] = sum;

		sum = 0;
		for(int j = 0; j<m; j++) {
			int cnt = 0;
			if(i>0) if(g[i-1][j] == g[i][j]) cnt++;
			if(i<n-1) if(g[i+1][j] != g[i][j]) cnt++;
			if(j>0) if(g[i][j-1] == g[i][j]) cnt++;
			if(j<m-1) if(g[i][j+1] == g[i][j]) cnt++;
			sum +=cnt*cnt;
		}
		if(i) dp[i][0] = std::max(dp[i][0],dp[i-1][0]+sum);
		else dp[i][0] = std::max(sum,dp[i][0]);

		sum = 0;
		for(int j = 0; j<m; j++) {
			int cnt = 0;
			if(i>0) if(g[i-1][j] != g[i][j]) cnt++;
			if(i<n-1) if(g[i+1][j] == g[i][j]) cnt++;
			if(j>0) if(g[i][j-1] == g[i][j]) cnt++;
			if(j<m-1) if(g[i][j+1] == g[i][j]) cnt++;
			sum +=cnt*cnt;
		}
		if(i) dp[i][0] = std::max(dp[i][0],dp[i-1][1]+sum);
		else dp[i][0] = std::max(sum,dp[i][0]);

		sum = 0;
		for(int j = 0; j<m; j++) {
			int cnt = 0;
			if(i>0) if(g[i-1][j] != g[i][j]) cnt++;
			if(i<n-1) if(g[i+1][j] != g[i][j]) cnt++;
			if(j>0) if(g[i][j-1] == g[i][j]) cnt++;
			if(j<m-1) if(g[i][j+1] == g[i][j]) cnt++;
			sum +=cnt*cnt;
		}
		if(i) dp[i][1] = std::max(dp[i][1],dp[i-1][0]+sum);
		else dp[i][1] = std::max(sum,dp[i][1]);
//		if(i)dp[i][0] = dp[i-1][0]+sum,dp[i][1] = dp[i-1][1]+sum;
//		else dp[i][0] = sum,dp[i][1] = sum;
//		sum = 0;
//		for(int j = 0;j<m;j++){
//			int cnt = 0;
//			if(i>0) if(g[i-1][j] != g[i][j]) cnt++;
//			if(i<n-1) if(g[i+1][j] != g[i][j]) cnt++;
//			if(j>0) if(g[i][j-1] == g[i][j]) cnt++;
//			if(j<m-1) if(g[i][j+1] == g[i][j]) cnt++;
//			sum +=cnt*cnt;
//		}
//		if(i) dp[i][0] = std::max(dp[i][0],dp[i-1][1]+sum),dp[i][1] = std::max(dp[i][1],dp[i-1][0]+sum);
//		else dp[i][0] = std::max(dp[i][0],sum),dp[i][1] = std::max(dp[i][1],sum);
	}
	std::cout<<std::max(dp[n-1][0],dp[n-1][1]);
	return 0;
}
/*
4 4
1010
1111
1011
1100
 */
