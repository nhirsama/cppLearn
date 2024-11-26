/*
//模板
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
	#define cin fin
	#define cout fout
	ifstream fin("Testlib.in");
	ofstream fout("main.out");

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
/*
//P1032 [NOIP2002 提高组] 字串变换
//AcWing 190. 字串变换
#include <bits/stdc++.h>
using namespace std;
string A[6],B[6];
string begin1,end1;
int n =0;

int extend(queue<string> &q,unordered_map<string,int> &mpA,unordered_map<string,int> &mpB,string a[6],string b[6]) {
	int d = mpA[q.front()];
	while (q.size() && mpA[q.front()]==d) {
		auto fr = q.front();
		q.pop();

		for (int i = 0;i<n;i++) {
			for (int j = 0;j<fr.size();j++) {
				if (fr.substr(j,a[i].size()) == a[i]) {
					string temp = fr.substr(0,j) + b[i] + fr.substr(j+a[i].size());
					if (mpB.count(temp)) return mpB[temp]+d+1;
					if (mpA.count(temp)) continue;
					mpA[temp] = d+1;
					q.push(temp);
				}
			}
		}
	}
	return 11;
}
int bfs() {
	if (begin1 == end1) return 0;
	int stop = 0;
	queue<string> be,en;
	unordered_map<string,int> mapBe,mapEn;
	be.push(begin1);en.push(end1);
	mapBe[begin1] = 0;
	mapEn[end1] = 0;
	while (!be.empty() && !en.empty()) {
		int t;
		if (be.size() < en.size()) {
			t = extend(be,mapBe,mapEn,A,B);
		}
		else t = extend(en,mapEn,mapBe,B,A);
		if (t <= 10) return t;
		if (++ stop == 10) return -1;
	}
	return -1;
}
int main() {
	cin>>begin1>>end1;
	getchar();
	// for (int i = 0;i<6;i++)
	// {
	// 	string s;
	// 	getline(cin, s);
	// 	istringstream is(s); //将s放入is流中
	// 	if(s.size() == 0) //如果读入的数据个数是0个，就说明输入结束了
	// 		break;
	// 	is >> A[n] >> B[n];
	// 	n++;
	// }
	while (cin>>A[n]>>B[n]) n++;//只有在读入文件时cin的返回值才为0
	//建议以后在洛谷等OJ上使用该方式提交
	int t =bfs();
	if (t == -1) cout<<"NO ANSWER!";
	else cout<<t;
	return 0;
}
*/
/*
//P1219 [USACO1.5] 八皇后 Checker Challenge
#include <bits/stdc++.h>
using namespace std;
int arr[20][20];
int n;
bool st[20];
bool sd[50],sd2[50];
int ans = 0;
int a[3][20];
void dfs(int i) {
	if (i == n) {
		ans++;
		return;
	}
	for (int j = 1; j <= n; j++) {
		if (st[j])continue;
		if (sd[j+i] || sd2[j-i+n])continue;
		if (ans <3) a[ans][i] = j;
		sd[i+j] = true;
		sd2[j-i+n] = true;
		st[j] = true;
		dfs(i + 1);
		st[j] = false;
		sd[i+j] = false;
		sd2[j-i+n] = false;
	}
}
int main() {
	cin>>n;
	dfs(0);
	for (int i = 0; i<3;i++) {
		for (int j = 0; j<n; j++) {
			if (a[i][j] == 0) {
				a[i][j] = a[i-1][j];
			}
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<ans;
	return 0;
}
*/
/*
//P1219 [USACO1.5] 八皇后 Checker Challenge
//面向答案编程版（）
#include <bits/stdc++.h>
using namespace std;
int arr[20][20];
int n;
bool st[20];
bool sd[50],sd2[50];
int ans = 0;
int a[3][20];
int ansArr[] = {0,0,0,0,0,0,4,40,92,352,724,2680,14200,73712,365596,2279184};
void dfs(int i) {
	if (i == n) {
		ans++;
		return;
	}
	for (int j = 1; j <= n; j++) {
		if (st[j])continue;
		if (sd[j+i] || sd2[j-i+n])continue;
		if (ans <3) a[ans][i] = j;
		sd[i+j] = true;
		sd2[j-i+n] = true;
		st[j] = true;
		dfs(i + 1);
		st[j] = false;
		sd[i+j] = false;
		sd2[j-i+n] = false;
		//懒得存每个数的输出了，直接搜索就行了
		if (ans >= 3) {
			break;
		}
	}
}
int main() {
	cin>>n;
	dfs(0);
	for (int i = 0; i<3;i++) {
		for (int j = 0; j<n; j++) {
			if (a[i][j] == 0) {
				a[i][j] = a[i-1][j];
			}
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	//cout<<ans;//突然想试试面向答案编程
	cout<<ansArr[n];
	return 0;
}
*/
/*
//P2730 [USACO3.2] 魔板 Magic Squares
#include <bits/stdc++.h>
using namespace std;
string start = "12345678",endStr;
unordered_map<string,pair<string,char>> mp1;
string FunA(string str) {
	string temp = "";
	for(int i=str.length()-1;i>=0;i--) {
		temp += str[i];
	}
	return temp;
}
string FunB(string str) {
	string temp = "";
	temp += str[3] + str.substr(0,3);
	temp += str.substr(5) + str[4];
	return temp;
}
string FunC(string str) {
	char a = str[6];
	str[6] = str[5];
	str[5] = str[2];
	str[2] = str[1];
	str[1] = a;
	return str;
}
int bfs() {
	queue<string> q;
	unordered_map<string,int> mp;
	q.push(start);
	mp1[start] = pair<string,char>(start,-1);
	while (!q.empty()) {
		string s = q.front();
		q.pop();
		if (s == endStr) {
			return mp[s];
		}
		string a = FunA(s);
		if (mp.count(a) == 0) {
			mp[a] = mp[s]+1;
			q.push(a);
			mp1[a] = pair<string,char>(s,'A');
		}
		a = FunB(s);
		if (mp.count(a) == 0) {
			mp[a] = mp[s]+1;
			q.push(a);
			mp1[a] = pair<string,char>(s,'B');
		}
		a = FunC(s);
		if (mp.count(a) == 0) {
			mp[a] = mp[s]+1;
			q.push(a);
			mp1[a] = pair<string,char>(s,'C');
		}
	}
	return -1;
}
int main() {
	for (int i = 0;i <8;i++) {
		char a;
		cin>>a;
		endStr += a;
	}
	cout<<bfs()<<'\n';
	stack<char> StS;
	string aaa = endStr;
	while (mp1[aaa].second != -1) {
		StS.push(mp1[aaa].second);
		aaa = mp1[aaa].first;
	}
	int num = 0;
	while (!StS.empty()) {
		cout<<StS.top();
		StS.pop();
		if (++num == 60) {
			cout<<"\n";
			num = 0;
		}
	}
	return 0;
}
*/
/*
//蓝桥杯B好数，超时
#include <bits/stdc++.h>
using namespace std;
int N;
bool Func(string &str){
	for (int i = 0;i< str.length();i++){
		if (i & 1){
			if(!(str[str.length()-1-i]-'0' & 1)){}
			else return false;
		}
		else{
			if(str[str.length()-1-i]-'0' & 1){}
			else return false;
		}
	}
	return true;
}
int main(){
	int ans = 0;
	cin>>N;
	N++;
	while(N--){
		if (!(N & 1)) continue;
		string str = to_string(N);
		if(Func(str)) ans++;
	}
	cout<<ans;
	return 0;
}
*/
/*
//P10424 [蓝桥杯 2024 省 B] 好数
#include <bits/stdc++.h>
using namespace std;
bool ifGood(int n) {
	int a = 1;
	while (n > 0) {
		if (n % 2 != a %2) {
			return false;
		}
		a++;
		n = n / 10;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (ifGood(i)) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
*/
/*
//城堡问题
//P1457 [USACO2.1] 城堡 The Castle
//第一个AC的蓝题，值得纪念
#include <bits/stdc++.h>
using namespace std;
int m,n;
int arr[100][100];
bool st[100][100];
int room[100][100][2];
struct m {
	int x;
	int y;
};
int ans = 0,area = 0;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int bfs(int a,int b) {
	bool stroom[100][100];
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++) {
			stroom[i][j]=false;
		}
	}
	st[a][b] = true;
	stroom[a][b] = true;
	queue<struct m> q;
	q.push({a,b});
	int area = 1;
	while(!q.empty()) {
		struct m temp = q.front();
		for(int i = 0; i < 4 ;i++) {
			int x = temp.x + dx[i];
			int y = temp.y + dy[i];
			if(st[x][y]) continue;
			if(x < 1 || x > m || y < 1 || y > n) continue;
			if(arr[temp.x][temp.y] >> i & 1) continue;
			q.push({x,y});
			st[x][y] = true;
			stroom[x][y] = true;
			area ++;
		}
		q.pop();
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if (stroom[i][j]) {
				room[i][j][0] = area;
				room[i][j][1] = ans;
			}
		}
	}
	return area;
}
int main() {
	cin>>n>>m;
	for(int i =1 ; i<=m ; i++) {
		for(int j =1 ; j<=n ; j++) {
			cin>>arr[i][j];
		}
	}

	for(int i =1 ; i<=m ; i++) {
		for(int j =1 ; j<=n ; j++) {
			if(!st[i][j]) {
				area = max(area,bfs(i,j));
				ans++;
			}
		}
	}
	int xx = 0,yy = 0;
	int maxRoom = 0;
	char NE;
	for(int i =1 ; i<=m ; i++) {
		for(int j =1 ; j<=n ; j++) {
			if (room[i][j][1] != room[i-1][j][1]) {
				if (room[i-1][j][0] + room[i][j][0]>maxRoom) {
					xx = i;
					yy = j;
					maxRoom = room[i-1][j][0] + room[i][j][0];
					NE = 'N';
					continue;
				}
				else if (room[i-1][j][0] + room[i][j][0]==maxRoom) {
					if (j<yy || (j==yy && i>xx)) {
						xx = i;
						yy = j;
						maxRoom = room[i-1][j][0] + room[i][j][0];
						NE = 'N';
						continue;
					}
				}
			}
			if (room[i][j][1] != room[i][j+1][1]) {
				if (room[i][j+1][0] + room[i][j][0]>maxRoom) {
					xx = i;
					yy = j;
					maxRoom = room[i][j+1][0] + room[i][j][0];
					NE = 'E';
					continue;
				}
				else if (room[i][j+1][0] + room[i][j][0]==maxRoom) {
					if (j<yy || (j==yy && i>xx)) {
						xx = i;
						yy = j;
						maxRoom = room[i][j+1][0] + room[i][j][0];
						NE = 'E';
						continue;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	cout<<area<<endl;
	cout<<maxRoom<<endl;
	cout<<xx<<' '<<yy<<' '<<NE<<endl;
	return 0;
}
*/
/*
//P1135 奇怪的电梯
#include <bits/stdc++.h>
using namespace std;
int N,A,B;
int arr[10010];
bool st[10010];
int ans = 0;
int dfs() {
	queue<pair<int,int>> q;
	q.emplace(A,0);
	st[A] = true;
	if (A == B)return 0;
	while (!q.empty()){
		pair<int,int> n = q.front();
		q.pop();
		int dx[] = {arr[n.first] + n.first,n.first - arr[n.first]};
		for (int i : dx) {
			if (st[i])continue;
			if (i<1 || i>N) continue;
			q.emplace(i,n.second+1);
			st[i] = true;
			if (i == B)return n.second+1;
		}
	}
	return -1;
}
int main() {
	#define cin fin
	#define cout fout
	ifstream fin("Testlib.in");
	ofstream fout("main.out");
	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int m = dfs();
	cout << m;
    return 0;
}
*/
/*
//P1019 [NOIP2000 提高组] 单词接龙
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
string strArr[23];
int st[23];
int n;
int dfs(int aa,int len) {
	int max1 = 0;
	for (int i = 1;i<=n;i++) {
		if (st[i] >= 2)continue;
		int Len = strArr[aa].length()-strArr[i].length();

		for (int j = strArr[aa].length()-1;j>max(0,Len);j--) {
			// string aaa = strArr[aa].substr(j);
			// string bbb = strArr[i].substr(0,strArr[aa].length()-j);
			if (strArr[aa].substr(j) == strArr[i].substr(0,strArr[aa].length()-j)) {
				st[i] ++;
				int maxA = dfs(i,len+j-Len);
				st[i] --;
				if (maxA > max1) {
					max1 = maxA;
				}
				break;
			}
		}
	}
	return max(len,max1);
}
int main() {
	#define cin fin
	#define cout fout
	ifstream fin("Testlib.in");
	ofstream fout("main.out");

	cin >> n;
	for (int i =1; i <= n; i++) {
		cin >> strArr[i];
	}
	char startChar;
	cin >> startChar;
	int max1 = 0;
	for (int i =1; i <= n; i++) {
		if (strArr[i][0] == startChar) {
			st[i]++;
			int a = dfs(i,strArr[i].length());
			st[i]--;
			if (a > max1) {
				max1 = a;
			}
		}
	}
	cout << max1;
	return 0;
}
*/
