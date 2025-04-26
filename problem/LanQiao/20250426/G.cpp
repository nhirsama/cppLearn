#include<bits/stdc++.h>
using i64 = long long int ;
int dp[2000][2000][2];
int main() {
	int n,m;
	std::cin>>n>>m;

	std::vector<std::string> g(n);
	for(int i = 0; i<n; i++) {
		std::cin>>g[i];
	}
	int dx[] = {0,0,-1,1};
	int dy[] = {1,-1,0,0};
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			for(int k = 0; k<4; k++) {
				int ix = i+dx[k];
				int iy = j+dy[k];
				if(ix<0 || ix >=n || iy<0 || iy>=m) continue;
				dp[i][j][0]+=(g[i][j] == g[ix][iy]);
				if(k>=2) dp[i][j][1] +=(g[i][j] != g[ix][iy]);
				else dp[i][j][1] +=(g[i][j] == g[ix][iy]);
			}
		}
	}
	i64 ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			ans+=std::max(dp[i][j][0]*dp[i][j][0],dp[i][j][1]*dp[i][j][1]);
		}
	}
	std::cout<<ans<<std::endl;
	return 0;
}
/*
4 4
1010
1111
1011
1100
 */
