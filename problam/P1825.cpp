#include <bits/stdc++.h>
using namespace std;
typedef pair<int ,int> PII;
#define x first
#define y second
int N,M;
int arr[350][350];
bool st[350][350];
int tp[27][2][2];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int ans = 0;
int mm[350][350];
int bfs(int a,int b){
	queue<PII> q;
	q.push(make_pair(a,b));
	st[a][b] = true;
	while(!q.empty()){
		PII p = q.front();
		q.pop();
		if(arr[p.x][p.y] == '='){
			return mm[p.x][p.y];
		}
		for(int i = 0;i<=3;i++){
			int ix = p.first + dx[i];
			int iy = p.second + dy[i];
			if(ix<=0 || ix>N || iy<= 0 || iy>M)continue;
			if(st[ix][iy])continue;
			if(arr[ix][iy] == '#')continue;
			if('A'<= arr[ix][iy] && arr[ix][iy] <= 'Z'){
				if(tp[arr[ix][iy]-'A'+1][0][0] == ix && tp[arr[ix][iy]-'A'+1][0][1] == iy ){
					st[tp[arr[ix][iy]-'A'+1][1][0]][tp[arr[ix][iy]-'A'+1][1][1]] = true;
					st[ix][iy] = true;
					q.push(make_pair(tp[arr[ix][iy]-'A'+1][1][0],tp[arr[ix][iy]-'A'+1][1][1]));
					mm[tp[arr[ix][iy]-'A'+1][1][0]][tp[arr[ix][iy]-'A'+1][1][1]] = mm[p.x][p.y]+1;
				}
				else{
					st[tp[arr[ix][iy]-'A'+1][0][0]][tp[arr[ix][iy]-'A'+1][0][1]] = true;
					q.push(make_pair(tp[arr[ix][iy]-'A'+1][0][0],tp[arr[ix][iy]-'A'+1][0][1]));
					mm[tp[arr[ix][iy]-'A'+1][0][0]][tp[arr[ix][iy]-'A'+1][0][1]] = mm[p.x][p.y]+1;
					st[ix][iy] = true;
				}
			}
			else{
				q.push(make_pair(ix,iy));
				st[ix][iy] = true;
				mm[ix][iy] = mm[p.x][p.y]+1;
			}
		}
	} 
	return -1;
}
int main(){
	cin>>N>>M;
	for(int i =1 ;i<=N;i++){
		for(int j =1;j<=M;j++){
			scanf("%c",&arr[i][j]);
			if('A'<=arr[i][j] && arr[i][j]<='Z'){
				if(tp[arr[i][j]-'A'+1][0][0] == 0){
					tp[arr[i][j]-'A'+1][0][0] = i;
					tp[arr[i][j]-'A'+1][0][1] = j;
				}
				else if(tp[arr[i][j]-'A'+1][1][0] == 0){
					tp[arr[i][j]-'A'+1][1][0] = i;
					tp[arr[i][j]-'A'+1][1][1] = j;
				}
			}
		}
	}
	for(int i = 1;i<=N;i++){
		for(int j =1;j<=M;j++){
			if(arr[i][j] == '@'){
			cout<<bfs(i,j);
			}
		}
	}
	return 0;
}

