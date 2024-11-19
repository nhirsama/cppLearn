/*
// CF1063B Labyrinth	//错误程序，改天重写一个
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
char arr[2005][2005];
int n,m;
int r,c;
int xl,xr;
bool st[2005][2005];
//int toXY[2005][2005][2];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int to[2005][2005][2];
int ans = 1;
int main(){
	cin>>n>>m;
	cin>>r>>c>>xl>>xr;
	for (int i =1;i<=n;i++){
		for (int j = 1 ; j<= m;j++){
			cin>>arr[i][j];
		}
	}
	queue<pair<int,int> >q;
	q.push(make_pair(r,c));
	st[r][c] = true;
	while(!q.empty()){
		pair<int ,int>p = q.front();
		q.pop();
		for (int i =0;i < 4 ;i++){
			int x = p.x + dx[i];
			int y = p.y + dy[i];
			if(x<1 || x > n || y < 1 || y > m)continue;
			if(dy[i] == -1 && to[p.x][p.y][0]>= xl) continue;
			if(dy[i] == 1 && to[p.x][p.y][1] >= xr)continue;
			if(st[x][y]) {
				if(to[p.x][p.y][0] > to[x][y][0]-1)continue;
				if(to[p.x][p.y][1] > to[x][y][1]-1)continue;
			}
			if(arr[x][y] == '.'){
				if(st[x][y])ans--;
				st[x][y] = true;
				ans++;
				q.push(make_pair(x,y));
				if(dy[i] == -1 && to[x][y][0] == 0)to[x][y][0] = to[p.x][p.y][0]+1;
				if(dy[i] == -1 && to[x][y][0] != 0)to[x][y][0] = min(to[p.x][p.y][0]+1,to[x][y][0]);
				if(dy[i] == 1 && to[x][y][1] == 0)to[x][y][1] = to[p.x][p.y][1]+1;
				if(dy[i] == 1 && to[x][y][1] != 0)to[x][y][1] = min(to[p.x][p.y][1]+1,to[x][y][1]);
				else {
					to[x][y][0] = to[p.x][p.y][0];
					to[x][y][1] = to[p.x][p.y][1];
				}
			}
		}
	}
	cout << ans;
	return 0;
}
*/