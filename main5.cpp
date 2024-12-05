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
/*
//P6363 [传智杯 #2 初赛] 软件工程实习
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
int arr[30];
vector <pair<int ,char>> arrm;
bool sortCmp(pair<int ,char> a,pair<int ,char> b) {
	if(a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}
int main() {
#define cin fin
#define cout fout
	ifstream fin("Testlib.in");
	ofstream fout("main.out");
	int n,k;
	arrm.emplace_back(0,0);
	cin >> n >> k;
	for (int i =1; i<=n; i++) {
		int m;
		char c;
		cin >> m >>c;
		arrm.emplace_back(m,c);
	}
	int team[30][30];
	float teamx[30] = {0};
	for (int i =1; i<=k; i++) {
		for (int j =1; j<=k; j++) {
			cin >> team[j][i];
			teamx[j] += team[j][i];
		}
	}
	for (int i =1; i<=k; i++) {
		float sum2 = 0;
		float num = 0;
		teamx[i] = teamx[i]/k;
		for (int j =1; j<=k; j++) {
			if (abs(team[i][j]-teamx[i]) <= 15) {
				sum2 += team[i][j];
				num++;
			}
		}
		arr[i] = (int)round(sum2/num);
	}
	for (int i =1; i<=n; i++) {
		arrm[i].first = (int)round(arr[arrm[i].second-'A'+1]*0.4+arrm[i].first*0.6);
	}
	sort(arrm.begin()+1,arrm.end(),sortCmp);
	for (int i =1;i <= n;i++) {
		cout << arrm[i].first << " " << arrm[i].second << '\n';
	}

	return 0;
}
*/
/*
//P6364 [传智杯 #2 初赛] 1024 程序员节发橙子
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
int arr[1000010];
int main() {
#define cin fin
#define cout fout
	ifstream fin("Testlib.in");
	ofstream fout("main.out");
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int ans = 1;
	int nn = 1;
	for (int i = 0; i < n-1; i++) {
		if (arr[i] != arr[i + 1]) {
			nn++;
			ans+=nn;
		}
		else {
			ans+=nn;
		}
	}
	cout << ans << endl;
	return 0;
}
*/
/*
//P6365 [传智杯 #2 初赛] 众数出现的次数
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
int arr[1000050][2];
int main() {
#define cin fin
#define cout fout
	ifstream fin("Testlib.in");
	ofstream fout("main.out");
	map<int,int> mp;
	int n;
	cin >> n;
	for (int i =1 ; i <= n ; i++) {
		cin >> arr[i][0] >> arr[i][1];
		arr[i][1] = arr[i][0] ^ arr[i][1];
	}
	for (int i = 1 ; i <= n ; i++) {
		if (arr[i][0] == arr[i][1]) {
			mp[arr[i][0]]++;
		}
		else {
			mp[arr[i][0]]++;
			mp[arr[i][1]]++;
		}
	}
	int maxNum = -5;
	int maxCnt = -5;
	for (auto a : mp) {
		if (a.second > maxNum) {
			maxNum = a.second;
			maxCnt = a.first;
		}
		else if (a.second == maxNum && a.first < maxCnt) {
			maxCnt = a.first;
		}
	}
	cout << maxCnt << endl;
	return 0;
}
*/
/*
//P1042 [NOIP2003 普及组] 乒乓球
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
char arr[100100];
int main() {
#define cin fin
#define cout fout
	ifstream fin("Testlib.in");
	ofstream fout("main.out");
	int n = 0;
	while (true) {
		char c;
		cin >> c;
		if (c == 'E') break;
		arr[n++] = c;
	}
	arr[n] = 'E';
	int m = 0;
	int Wwin = 0,Lwin = 0;
	for (int i = 0; i <= n; i++) {
		if ((Wwin >= 11 || Lwin >= 11) && abs(Wwin-Lwin) >= 2) {
			cout << Wwin << ':' << Lwin << '\n';
			Wwin = 0;
			Lwin = 0;
			m = 0;
		}
		if (arr[i] == 'W') {
			Wwin++;
		}
		else if (arr[i] == 'L') {
			Lwin++;
		}
		else if (arr[i] == 'E') {
			cout << Wwin << ':' << Lwin << '\n';
		}
		m++;
	}
	Wwin = 0;
	Lwin = 0;
	m = 0;
	cout << endl;
	for (int i = 0; i <= n; i++) {
		if ((Wwin >= 21 || Lwin >= 21) && abs(Wwin-Lwin) >= 2) {
			cout << Wwin << ':' << Lwin << '\n';
			Wwin = 0;
			Lwin = 0;
			m = 0;
		}
		if (arr[i] == 'W') {
			Wwin++;
		}
		else if (arr[i] == 'L') {
			Lwin++;
		}
		else if (arr[i] == 'E') {
			cout << Wwin << ':' << Lwin << '\n';
		}
		m++;
	}
	return 0;
}
*/
/*
//P2895 [USACO08FEB] Meteor Shower S
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define x first
#define y second
int arr[500][500] = {0};
int dx[] = {0,-1,0,1,0};
int dy[] = {-1,0,1,0,0};
bool st[500][500] = {0};
int arrm[500][500] = {0};
int bfs(){
	int ans = 0;
	queue <PII> q;
	q.push(make_pair(0,0));
	st[0][0] = true;
	while(!q.empty()){
		PII p = q.front();
		q.pop();
		if(arr[p.x][p.y] == 0){
			return arrm[p.x][p.y];
		}
		for(int i = 0;i<=3;i++){
			int bx = p.x+dx[i];
			int by = p.y+dy[i];
			if(bx<0 || bx>=500 || by<0 || by >= 500) continue;
			if(st[bx][by])continue;
			if(arr[bx][by] <= arrm[p.x][p.y]+1 && arr[bx][by] != 0)continue;
			st[bx][by] = true;
			q.push(make_pair(bx,by));
			arrm[bx][by] = arrm[p.x][p.y]+1;
		}
	}
	return -1;
}
int main(){
	int m;
	scanf("%d",&m);
	for (int i =1;i<=m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		//if(c == 0)c = -1;
		for(int j = 0;j <= 4;j++){
			int mx = a+dx[j];
			int my = b+dy[j];
			if(mx<0 || my <0)continue;
			if(arr[mx][my] > c || arr[mx][my] == 0){
				if(c == 0)st[mx][my] = true;
				arr[mx][my] = c;
			}
		}
	}
	cout<< bfs();
	return 0;
}
*/
/*
//P1825 [USACO11OPEN] Corn Maze S
#include <bits/stdc++.h>
using namespace std;
typedef pair<int ,int> PII;
#define x first
#define y second
int N,M;
char arr[350][350];
bool st[350][350];
int tp[27][2][2];
int dx[] = {0,-1,0,1,0};
int dy[] = {-1,0,1,0,0};
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
		for(int i = 0;i<=4;i++){
			int ix = p.first + dx[i];
			int iy = p.second + dy[i];
			if(ix<=0 || ix>N || iy<= 0 || iy>M)continue;
			if(st[ix][iy])continue;
			if(arr[ix][iy] == '#')continue;
			if('A'<= arr[ix][iy] && arr[ix][iy] <= 'Z'){
				if(tp[arr[ix][iy]-'A'+1][0][0] == ix && tp[arr[ix][iy]-'A'+1][0][1] == iy ){
					st[tp[arr[ix][iy]-'A'+1][1][0]][tp[arr[ix][iy]-'A'+1][1][1]] = true;
					st[ix][iy] = true;
					q.push(make_pair(ix,iy));
					mm[ix][iy] = mm[p.x][p.y] + 3;
					q.push(make_pair(tp[arr[ix][iy]-'A'+1][1][0],tp[arr[ix][iy]-'A'+1][1][1]));
					mm[tp[arr[ix][iy]-'A'+1][1][0]][tp[arr[ix][iy]-'A'+1][1][1]] = mm[p.x][p.y]+1;
				}
				else{
					st[tp[arr[ix][iy]-'A'+1][0][0]][tp[arr[ix][iy]-'A'+1][0][1]] = true;
					q.push(make_pair(tp[arr[ix][iy]-'A'+1][0][0],tp[arr[ix][iy]-'A'+1][0][1]));
					mm[tp[arr[ix][iy]-'A'+1][0][0]][tp[arr[ix][iy]-'A'+1][0][1]] = mm[p.x][p.y]+1;
					st[ix][iy] = true;
					q.push(make_pair(ix,iy));
					mm[ix][iy] = mm[p.x][p.y] + 3;
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
			cin>>arr[i][j];
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
*/
/*
//P1047 [NOIP2005 普及组] 校门外的树
#include <bits/stdc++.h>
using namespace std;
bool arr[10005];
int main() {
	int l,m;
	cin>>l>>m;
	for (int i = 0;i<=l;i++) {
		arr[i] = true;
	}
	for (int i = 1;i<=m;i++) {
		int x,y;
		cin>>x>>y;
		for (int j=x;j<=y;j++) {
			arr[j] = false;
		}
	}
	int ans = 0;
	for (int i = 0;i<=l;i++) {
		if (arr[i]) {ans++;}
	}
	cout<<ans<<endl;
	return 0;
}
*/
/*
//P10898 [蓝桥杯 2024 省 C] 拼正方形
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a = 7385137888721;
	long long b = 10470245;
	a = (long long)sqrt(a)*2;
	while(a*4+4<=b){
		a+=2;
		b-=a*4+4;
	}
	cout << a;
	return 0;
}
*/
/*
//P10423 [蓝桥杯 2024 省 B] 填空问题
#include <bits/stdc++.h>
using namespace std;
int main(){
	double ans[2];
	ans[0] = 43*42/2+7*43;
	long long chang = 343720*2;
	long long kuan = 233333*2;
	int m = 1059;
	int n = 1768;
	ans[1] = sqrt(chang*m*chang*m+kuan*n*kuan*n);
	//cout<<ans[1];
	//	for(int i = 1;i<=10000;i++){
	//		for(int j = 1;j<=10000;j++){
	//			if(i*chang*17 == j*kuan*15)cout<<i<< ' ' <<j<<'\n';
	//		}
	//	}
		char T;
		cin >> T;
		if(T == 'A')cout<<ans[0]<<endl;
		if(T == 'B')printf("%.2lf",ans[1]);
	return 0;
}
*/
/*
//P1601 A+B Problem（高精）
#include <bits/stdc++.h>
using namespace std;
vector <char> a;
vector <char> b;
vector <char> add(vector <char> &aa,vector <char> &bb){
	if(aa.size()<bb.size())return add(bb,aa);
	for(int i=  0;i<aa.size();i++){
		if(i<bb.size())aa[i] += bb[i];
		if(aa[i]>=10){
			if (i == aa.size()-1)aa.push_back(1);
			else aa[i+1]++;
			aa[i] %=10;
		}
	}
	return aa;
}
int main(){
	string mm;
	string bb;
	cin>>mm>>bb;
	for(int i = mm.size()-1;i>=0;i--){
		a.push_back(mm[i]-'0');
	}
	for(int i = bb.size()-1;i>=0;i--){
		b.push_back(bb[i]-'0');
	}
	a = add(a,b);
	for (int i = a.size()-1 ; i >= 0; i--) {
		cout<<(char)(a[i]+'0');
	}
	return 0;
}
*/
/*
//P1303 A*B Problem
//P1601 A+B Problem（高精）
#include <bits/stdc++.h>
using namespace std;
vector <char> a;
vector <char> b;
vector <char> add(vector <char> &aa,vector <char> &bb){
	if(aa.size()<bb.size())return add(bb,aa);
	for(int i=  0;i<aa.size();i++){
		if(i<bb.size())aa[i] += bb[i];
		if(aa[i]>=10){
			if (i == aa.size()-1)aa.push_back(1);
			else aa[i+1]++;
			aa[i] %=10;
		}
	}
	return aa;
}
vector <char> mul(vector <char> &aa,vector <char> &bb){
	if(aa.size()<bb.size())return mul(bb,aa);
	vector<char> c(aa.size()+bb.size()+1,0);
	for(int i = 0;i<aa.size();i++){
		for(int j = 0;j<bb.size();j++){
			c[i+j] += a[i]*b[j];
			c[i+j+1] += c[i+j]/10;
			c[i+j] %= 10;
		}
	}
	while(c.size()>1 && c.back() == 0)c.pop_back();
	return c;
}
int main(){
	string mm;
	string bb;
	cin>>mm>>bb;
	for(int i = mm.size()-1;i>=0;i--){
		a.push_back(mm[i]-'0');
	}
	for(int i = bb.size()-1;i>=0;i--){
		b.push_back(bb[i]-'0');
	}
	a = mul(a,b);
	for (int i = a.size()-1 ; i >= 0; i--) {
		cout<<(char)(a[i]+'0');
	}
	return 0;
}
*/
/*
//模板
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
// #define cin fin
// #define cout fout
// 	ifstream fin("Testlib.in");
// 	ofstream fout("main.out");
	int i  = 1;
	cout << (++i)+(++i);
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
void bfs() {

}
int main() {
	cin>>begin1>>end1;
	int n =0;
	while (cin>>A[n]>>B[n])n++;
	bfs();
	return 0;
}
*/
/*
//P1083 [NOIP2012 提高组] 借教室
//记得把文件读写流和define注释掉
//错误为爆ing以及遍历范围过小。
#include <bits/stdc++.h>
using namespace std;
int arr[1000050];
int N,M;
int arrM[1000050][3];
long long arra[1000050]{0};
bool Func(int m) {

	memset(arra,0,sizeof(arra));
	for (int i = 1; i <= m; i++) {
		arra[arrM[i][1]] += arrM[i][0];
		arra[arrM[i][2]+1] -= arrM[i][0];
	}
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += arra[i];
		if (sum > arr[i]) {
			return false;
		}
	}
	return true;
}
int main() {
#define cin fin
#define cout fout
	ifstream fin("inAndoutFile/P1083_21.in");
	ofstream fout("main.out");
	ios::sync_with_stdio(false);
	cin>>N>>M;
	for (int i = 1;i<=N;i++) {
		cin>>arr[i];
	}
	for (int i = 1;i<=M;i++) {
		cin>>arrM[i][0]>>arrM[i][1]>>arrM[i][2];
	}
	if (Func(M)) {
		cout<<0<<endl;
		return 0;
	}
	int l = 1;
	int r = M;
	while (l<r) {
		int m = (l+r)/2;
		if (Func(m)) l = m+1;
		else r = m;
	}
	cout<<-1<<endl;
	cout<<l<<endl;
	return 0;
}
*/
/*
//P1044 [NOIP2003 普及组] 栈
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
long long dp[MAX][MAX];//下标1是pop的次数，下标2是push的次数；
int n;
void dpFunc() {
	for (int i = 0; i <= n; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i <= n;i++) {
		for (int j = i; j <= n; j++) {
			if (i==j) dp[i][j] = dp[i-1][j];
			else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
	}
}
int main() {
// #define cin fin
// #define cout fout
// 	ifstream fin("Testlib.in");
// 	ofstream fout("main.out");
	cin>>n;
	dpFunc();
	cout<<dp[n][n]<<endl;
	return 0;
}
*/
/*
//P1719 最大加权矩形
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
int arr[130][130];
int main() {
#define cin fin
#define cout fout
	ifstream fin("Testlib.in");
	ofstream fout("main.out");
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cin>>arr[i][j];
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	}
	int ans = 0;
	for(int i =1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			for(int i1 = i;i1<=n;i1++) {
				for(int j1 = j;j1<=n;j1++) {
					int cont = arr[i1][j1] - arr[i1][j-1] - arr[i-1][j1] + arr[i-1][j-1];
					if(ans < cont) {
						ans = cont;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
*/
/*
//P8783 [蓝桥杯 2022 省 B] 统计子矩阵
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
long long arr[530][530];
long long sum[530];
int main() {
#define cin fin
#define cout fout
	ifstream fin("Testlib.in");
	ofstream fout("main.out");
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			cin>>arr[i][j];
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			arr[i][j] += arr[i-1][j];
		}
	}
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		for (int j = i;j<=n;j++) {
			for (int kn = 1;kn<=m;kn++) sum[kn] = arr[j][kn] - arr[i-1][kn];
			long long sum1 = 0;
			for (int k1 = 1,k2 = 1;k1<=m;k1++) {
				sum1 += sum[k1];
				while (k2<=k1 && sum1 >k) {
					sum1 -= sum[k2];
					k2++;
				}
				ans += k1-k2+1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
*/