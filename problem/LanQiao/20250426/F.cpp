#include<bits/stdc++.h>
using i64 = long long int ;
i64 ans = 0;
int n,k;
void dfs(int cnt,std::vector <std::vector<int> > &g,std::vector<i64>&w,int u,int f) {
	if(cnt>k*2) return;
	for(auto i:g[u]) {
		if(i == f) {
			continue;
		}
		dfs(cnt+1,g,w,i,u);
	}
	ans+=w[u];
}
int main() {
	std::cin>>n>>k;
	std::vector<i64> w(n);
	std::vector <std::vector<int> > g(n);
	for(int i = 0; i<n; i++) {
		std::cin>>w[i];
	}
	for(int i = 1; i<n; i++) {
		int u,v;
		std::cin>>u>>v;
		u--,v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,g,w,0,0);
	std::cout<<ans<<std::endl;
	return 0;
}
/*
8 2
6 3 3 1 5 4 3 4
1 2
2 3
2 4
4 5
5 6
6 7
7 8
 */
