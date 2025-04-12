#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m,h;
	std::cin>>n>>m>>h;
	std::vector g(n+1,std::vector<int> (m+1));
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=m; j++) {
			std::cin>>g[i][j];
		}
	}
	int cnt = 0;
	int ansx =0,ansy = 0,anscnt = 0;
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=m; j++) {
			if(g[i][j] == 0) {
				int tcnt = 0;
				for(int ix = i-1; ix; ix--) {
					if(g[ix][j]<0) tcnt++;
					else if(g[ix][j]<h) {}
					else break;
				}
				for(int ix = i+1; ix<=n; ix++) {
					if(g[ix][j]<0) tcnt++;
					else if(g[ix][j]<h) {}
					else break;
				}
				for(int iy = j-1; iy; iy--) {
					if(g[i][iy]<0) tcnt++;
					else if(g[i][iy]<h) {}
					else break;
				}
				for(int iy = j+1; iy<=m; iy++) {
					if(g[i][iy]<0) tcnt++;
					else if(g[i][iy]<h) {}
					else break;
				}
				if(tcnt>anscnt) {
					anscnt = tcnt;
					ansx = i;
					ansy = j;
				} else if(tcnt == anscnt) {
					if(ansx > i) {
						ansx = i;
						ansy = j;
					} else if(ansx == i) {
						ansy = min(ansy,j);
					}
				}
				if(tcnt>=3) cnt++;
			}
		}

	}
	std::cout<<cnt<<endl;
	std::cout<<ansx-1<< ' '<<ansy-1<<endl;
}
