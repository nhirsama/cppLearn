/*
//模板
#include <bits/stdc++.h>
using namespace std;
int main() {

	return 0;
}
*/
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
/*
//P2367 语文成绩
#include <bits/stdc++.h>
using namespace std;
int arr[5000010];
int main() {
	int n,p;
	scanf("%d %d",&n,&p);
	int a = 0;
	for (int i = 1;i <= n;i++) {
		scanf("%d",&arr[i]);
		arr[i] -= a;
		a += arr[i];
	}
	for (int i = 1; i <= p; i++) {
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		arr[x] += z;
		arr[y+1] -=z;
	}
	int ans = 0xFFFFFF,sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += arr[i];
		if (ans > sum)ans = sum;
	}
	cout << ans << endl;
	return 0;
}
*/
/*
//P4231 三步必杀
#include <bits/stdc++.h>
using namespace std;
int arr[10000005];
int arr1[10000005];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	scanf("%d %d",&n,&m);
	while(m--) {
		long long l,r,s,e;
		scanf("%lld %lld %lld %lld",&l,&r,&s,&e);
		int q = (e-s)/(r-l);
		arr[l]+=s;
		arr[r+1]-=e;
		arr1[l+1]+=q;
		arr1[r+1]-=q;
	}
	long long xorAns = 0;
	long long maxNum = arr[1];
	long long sum = 0;
	long long cF = 0;
	for (int i = 1; i <= n; i++) {
		cF += arr1[i];
		sum += cF + arr[i];
		xorAns ^= sum;
		if (sum > maxNum) {
			maxNum = sum;
		}
	}
	printf("%lld %lld\n",xorAns,maxNum);
	return 0;
}
*/