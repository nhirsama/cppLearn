/*
//模板
#include <bits/stdc++.h>
using namespace std;
int main() {
    return 0;
}
*/
/*
//A - Army
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[120];
int a,b;
int main() {
    cin>>n;
    arr[0] =0;
    for(int i=1;i<n;i++) {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }

    cin>>a>>b;
    cout << arr[b-1]-arr[a-1];
    return 0;
}
*/
/*
//B - 均分纸牌
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int arr[110];
    int sum = 0;
    int ans = 0;
    for (int i =1 ; i <= N ; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int aaa = sum / N;
    for (int i = 1 ; i < N ; i++) {
        if (aaa == arr[i]) {
            continue;
        }
        if (aaa > arr[i]) {
            arr[i+1] -= aaa-arr[i];
            arr[i] = aaa;
            ans++;
        }
        else {
            arr[i+1] += arr[i]-aaa;
            arr[i] = aaa;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
*/
/*
//D - Bar
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int ans = 0;
    string R18[] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    for (int i = 1; i <= n; i++) {
        string  line;
        cin >> line;
        if ('A' <= line[0] && line[0] <= 'Z') {
            for (auto s : R18) {
                if (s.compare(line) == 0) {
                    ans++;
                    break;
                }
            }
        }
        else {
            if ((line[1] == '\0')|| (line[0] == '1' && line[1] < '8' && line[2] == '\0') ) {
                ans ++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/
/*
//P5734 【深基6.例6】文字处理软件
#include <bits/stdc++.h>
using namespace std;
string input;
int main() {
    int q;
    cin >> q;
    cin >> input;
    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;
        switch (m) {
            case 1: {
                string s;
                cin >> s;
                input +=s;
                cout << input <<endl;
                continue;
            }
            case 2: {
                int a,b;
                cin >> a >> b;
                input = input.substr(a,b);
                cout << input << endl;
                continue;
            }
            case 3: {
                int a;
                string s;
                cin >> a>>s;
                input.insert(a,s);
                cout << input <<endl;
                continue;
            }
            case 4: {
                string s;
                cin >> s;
                int a = input.find(s);
                if (0<=  a <= input.size()) cout << a << endl;
                else cout << -1 << endl;
                continue;
            }
            default: ;
        }
    }
    return 0;
}
*/
/*
//P1162 填涂颜色
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100][100];
bool st[100][100];
struct que {
    int x;
    int y;
};
void bfs(int a, int b) {
    queue<struct que> q;
    bool flag = true;
    bool to2[100][100];
    q.push({a, b});

    while(!q.empty()) {
        struct que p = q.front();
        if (p.x == 1 || p.x == n ||  p.y == n || p.y == 1) {
            flag = false;
            // q.pop();
            // break;
        }
        if(arr[p.x-1][p.y] == 0 && !st[p.x-1][p.y]) {
            st[p.x-1][p.y] = true;
            q.push({p.x-1, p.y});
            to2[p.x-1][p.y] = true;
        }
        if(arr[p.x][p.y-1] == 0 && !st[p.x][p.y-1]) {
            st[p.x][p.y-1] = true;
            q.push({p.x, p.y-1});
            to2[p.x][p.y-1] = true;
        }
        if(arr[p.x+1][p.y] == 0 && !st[p.x+1][p.y]) {
            st[p.x+1][p.y] = true;
            q.push({p.x+1, p.y});
            to2[p.x+1][p.y] = true;
        }
        if(arr[p.x][p.y+1] == 0 && !st[p.x][p.y+1]) {
            st[p.x][p.y+1] = true;
            q.push({p.x, p.y+1});
            to2[p.x][p.y+1] = true;
        }
        q.pop();
    }
    if(!flag) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(to2[i][j])arr[i][j] = 2;
                if(to2[i][j])st[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // if(flag) {
    //     for(int i = 1; i <= n; i++) {
    //         for(int j = 1; j <= n; j++) {
    //             if(to2[i][j])arr[i][j] = 2;
    //             if(to2[i][j])st[i][j] = true;
    //         }
    //     }
    // }
    st[a][b] = true;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j =1 ; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i <=n+1; i++) {
        st[0][i] = true;
        st[i][0] = true;
        st[n+1][i] = true;
        st[i][n+1] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 0 && !st[i][j]) {
                bfs(i,j);
            }
            //st[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
/*
//P1162 填涂颜色
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100][100];
struct que {
    int x;
    int y;
};
void bfs(int a, int b) {
    queue<struct que> q;
    bool to2[100][100] = {false};
    q.push({a, b});
    while(!q.empty()) {
        struct que p = q.front();
        if(p.x < 1 || p.y < 1 || p.x > n || p.y > n) {
            q.pop();
            continue;
        }
        if(arr[p.x-1][p.y] == 2 && !to2[p.x-1][p.y]) {
            to2[p.x-1][p.y] = true;
            q.push({p.x-1, p.y});
        }
        if(arr[p.x][p.y-1] == 2 && !to2[p.x][p.y-1]) {
            to2[p.x][p.y-1] = true;
            q.push({p.x, p.y-1});
        }
        if(arr[p.x+1][p.y] == 2 && !to2[p.x+1][p.y]) {
            to2[p.x+1][p.y] = true;
            q.push({p.x+1, p.y});
        }
        if(arr[p.x][p.y+1] == 2 && !to2[p.x][p.y+1]) {
            to2[p.x][p.y+1] = true;
            q.push({p.x, p.y+1});
        }
        q.pop();
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(to2[i][j])arr[i][j] = 0;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j =1 ; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) arr[i][j] = 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i][1] == 2) bfs(i, 1);
        if (arr[i][n] == 2) bfs(i, n);
        if (arr[1][i] == 2) bfs(1, i);
        if (arr[n][i] == 2) bfs(n, i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
/*
//城堡问题
#include <bits/stdc++.h>
using namespace std;
int m,n;
int arr[ 100][100];
bool st[100][100];
struct m {
    int x;
    int y;
};
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int bfs(int a,int b) {
    st[a][b] = true;
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
            area ++;
        }
        q.pop();
    }
    return area;
}
int main() {
    cin>>m>>n;
    for(int i =1 ; i<=m ; i++) {
        for(int j =1 ; j<=n ; j++) {
            cin>>arr[i][j];
        }
    }
    int ans = 0,area = 0;
    for(int i =1 ; i<=m ; i++) {
        for(int j =1 ; j<=n ; j++) {
            if(!st[i][j]) {
                area = max(area,bfs(i,j));
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    cout<<area<<endl;
    return 0;
}
*/
/*
//P1141 01迷宫
#include <bits/stdc++.h>
using namespace std;
int arr[1010][1010];
bool st[1010][1010] = {false};
int findArr[100020][2];
int Num[100010];
int n,m;
struct a {
    int x;
    int y;
};
int ans = 2;
int dx[] = {-1,0,1,0};int dy[] = {0, -1,0,1};
void bfs(int a,int b) {
    int mm = 1;
    queue<struct a> q;
    //q.push({a,b});
    q.push({.x = a,.y = b});
    st[a][b] = true;
    while(!q.empty()) {
        struct a p = q.front();
        for(int i=0;i<4;i++) {
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            if(x<1 || x>n || y<1 || y>n) continue;
            if(st[x][y]) continue;
            if(arr[x][y] != arr[p.x][p.y]) {
                st[x][y] = true;
                mm++;
                q.push({x,y});
            }
        }
        arr[p.x][p.y] = ans;
        q.pop();
    }
    Num[ans] = mm;
    ans++;
}
int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d %d",&n,&m);
    //cin >> n >> m;
    for (int i =1 ; i <= n ; i++) {
        //getchar();
        scanf("\n");
        for (int j =1 ; j <= n ; j++) {
            scanf("%c",&arr[i][j]);
            //arr[i][j] = getchar();
        }
    }
    for (int i = 0; i< m ;i++) {
        scanf("%d %d",&findArr[i][0],&findArr[i][1]);
        //cin >> findArr[i][0] >> findArr[i][1];
    }
    for (int i =0 ; i < m  ; i++) {
        if(!st[findArr[i][0]][findArr[i][1]]) bfs(findArr[i][0],findArr[i][1]);
        printf("%d\n",Num[arr[findArr[i][0]][findArr[i][1]]]);
        //cout << Num[arr[findArr[i][0]][findArr[i][1]]] << '\n';
    }
    return 0;
}
*/
/*
//P1051 [NOIP2005 提高组] 谁拿了最多奖学金 //C17和C20编译还不一样，用C20在洛谷上提交就稳定WA
#include <bits/stdc++.h>
using namespace std;
struct student {
    char name[20];
    int ans;
    int a;
};
bool sortCmp(struct student a, struct student b) {
    if (a.ans == b.ans) {
        return a.a < b.a;
    }
    return a.ans > b.ans;
}
int main() {
    vector<struct student> students;
    int N;
    cin >> N;
    int sum = 0;
    int maxans = 0;
    char maxName[20];
    for (int i = 0; i < N; i++) {
        struct student s;
        int AverageScore;
        char EStu;
        int paper;
        int grade;
        char Ganbu;
        int ans = 0;
        cin >> s.name >> AverageScore>> grade >> Ganbu >> EStu >> paper;
        if (AverageScore > 80 && paper >= 1) ans+=8000;
        if (AverageScore > 85 && grade > 80) ans+=4000;
        if (AverageScore > 90) ans+=2000;
        if (AverageScore > 85 && EStu == 'Y') ans+=1000;
        if (grade > 80 && Ganbu == 'Y') ans+=850;
        s.a = i;
        s.ans = ans;
        sum+=ans;
        if (ans > maxans) {
            maxans = ans;
            for (int j = 0; j< 20 ;j++) {
                maxName[j] = s.name[j];
            }
        }
        students.push_back(s);
    }
    //sort(students.begin(), students.end(),sortCmp);
    cout << maxName << '\n' << maxans << endl;
    cout << sum << '\n';
    return 0;
}
*/
/*
//P1036 [NOIP2002 普及组] 选数
#include <bits/stdc++.h>
using namespace std;
int arr[5000010];
int k,n;
int ans = 0;
bool isPrime(long long q) {
    for (int i = 2; i <= sqrt(q);i++) {
        if (q % i == 0) {
            return false;
        }
    }
    return true;
}
void dfs(int a,long long b ,int c) {   //a深度、b是目前的和，c是起始位置。
    if(a == k) {
        if(isPrime(b)) ans++;
        return;
    }
    if(c>n) return;
    for (int i = c; i <= n;i++) {
        dfs(a+1,b+arr[i],i+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i =1; i<=n;i++) {
        cin>>arr[i];
    }
    dfs(0,0,1);
    cout<<ans;
    return 0;
}
*/
/*
//P1008 [NOIP1998 普及组] 三连击
#include <bits/stdc++.h>
using namespace std;
bool sr[10];
int a = 0;
void dfs(int a,int b) {
    if (a == 9) {
        int d = b / 1000000 ;
        int c = b / 1000 % 1000;
        int m = b % 1000;
        if (d == c / 2 &&  c /2 == m / 3) {
            cout << d << ' ' << c << ' ' << m << endl;
            return;
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (sr[i]) continue;
        sr[i] = true;
        dfs(a+1,b+i*static_cast<int>(pow(10, 8 - a)));
        sr[i] = false;
    }
}
int main() {
    dfs(0,0);
    return 0;
}
*/
/*
//P1451 求细胞数量 我tm直接爆搜
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int n,m;
char arr[110][110];
bool st[110][110] = {false};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int ans = 0;
void bfs(int i,int j) {
    queue<pair<int,int> > q;
    q.push(pair(i,j));
    st[i][j] = true;
    while(!q.empty()) {
        pair<int,int> p = q.front();
        for(int k=0;k<4;k++) {
            int x = p.x + dx[k];
            int y = p.y + dy[k];
            if(st[x][y])continue;
            if(x<1 || x > n || y < 1 || y > m) continue;
            if(arr[x][y] != '0') {
                q.push(pair(x,y));
                st[x][y] = true;
            }
        }
        q.pop();
    }
    ans++;
}
int main() {
    cin>>n>>m;
    for (int i =1 ; i<=n ; i++) {
        for (int j =1 ; j<=m ; j++) {
            cin>>arr[i][j];
        }
    }
    for (int i =1 ; i<=n ; i++) {
        for (int j =1 ; j<=m ; j++) {
            if(!st[i][j] && arr[i][j] != '0')bfs(i,j);
        }
    }
    cout << ans << '\n';
    return 0;
}
*/
/*
//P1443 马的遍历
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int n,m;
int arr[459][459];
int st[459][459];
int dx[] = {-2,-2,-1,1,2,2,1,-1};
int dy[] = {-1,1,2,2,1,-1,-2,-2};
void bfs(int a, int b) {
    queue<pair<int,int> > q;
    q.push(make_pair(a,b));
    st[a][b] = true;
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x = p.x+dx[i];
            int y = p.y+dy[i];
            if (st[x][y])continue;
            if (x<1 || x > n || y<1 || y > m) continue;
            q.push(make_pair(x,y));
            arr[x][y] = arr[p.x][p.y]+1;
            st[x][y] = true;
        }
    }
}
int main() {
    int cinX,cinY;
    cin >> n >> m;
    cin >> cinX >> cinY;
    bfs(cinX, cinY);
    // for (int i =1 ; i <= n ; i++) {
    //     for (int j =1 ; j <= m ; j++) {
    //         if(!st[i][j])bfs(i,j);
    //     }
    // }
    for (int i =1 ; i <= n; i++) {
        for (int j =1 ; j <= m ; j++) {
            if(i == cinX && j == cinY) cout << 0 << ' ';
            else if(arr[i][j] == 0) cout << -1 << ' ';
            else cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
*/
/*
//P1747 好奇怪的游戏
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int x1,y11;
int x2,y2;
int arr[45][45];
bool st[45][45];
int dx[] = {-2,-2,-1,1,2,2,1,-1,-2,-2,2,2};   //马的遍历坐标
int dy[] = {-1,1,2,2,1,-1,-2,-2,-2,2,2,-2};
void bfs(int a, int b) {
    queue<pair<int,int> > q;
    q.push(make_pair(a,b));
    st[a][b] = true;
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for (int i = 0; i < 12; i++) {
            int x = p.x+dx[i];
            int y = p.y+dy[i];
            if (st[x][y])continue;
            if (x<1 || x > a+3 || y<1 || y > b+3) continue;
            q.push(make_pair(x,y));
            arr[x][y] = arr[p.x][p.y]+1;
            st[x][y] = true;
        }
    }
}
int main() {
    cin >> x1 >> y11;
    cin >> x2 >> y2;
    bfs(x1, y11);
    int ansM1 = arr[1][1];
    for (int i = 1 ; i < x1+4 ; i++) {
        for (int j = 1 ; j < y11+4 ; j++) {
            arr[i][j] = 0;
            st[i][j] = false;
        }
    }
    bfs(x2, y2);
    int ansM2 = arr[1][1];
    cout << ansM1 << '\n' << ansM2 << '\n';
    return 0;
}
*/
/*
//T539826 202411G 三角含数
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int arr[7];
int s1[] = {1,1,1,1,1,1,1,1,1,1};
int s2[] = {2,2,2,2,3,3,3,4,4,5};
int s3[] = {3,4,5,6,4,5,6,5,6,6};
int s4[] = {4,3,3,3,2,2,2,2,2,2};
int s5[] = {5,5,4,4,5,4,4,3,3,3};
int s6[] = {6,6,6,5,6,6,5,6,5,4};
void dfs(int j) {
    for(int i=1;i<=6;i++) {
        arr[i] = j%10;
        j /=10;
    }
    for(int i=0;i<10;i++) {
        if(
            arr[s1[i]] + arr[s2[i]] > arr[s3[i]] && arr[s4[i]] + arr[s5[i]] > arr[s6[i]] &&
            arr[s2[i]] + arr[s3[i]] > arr[s1[i]] && arr[s4[i]] + arr[s6[i]] > arr[s5[i]] &&
            arr[s1[i]] + arr[s3[i]] > arr[s2[i]] && arr[s5[i]] + arr[s6[i]] > arr[s4[i]]
            ) {
            ans++;
            return;
        }
    }
}
int main() {
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++) {
        dfs(i);
    }
    cout<<ans<<endl;
    return 0;
}
*/
/*
//P1025 [NOIP2001 提高组] 数的划分
#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans = 0;
void dfs(int a,int b,int c) {   //a是深度，b是前几次迭代的和，k是开始的值
    if(b > n) return;
    if (a == k-1) {
        if(c<=n-b) {
            ans++;
        }
        return;
    }
    // if(a == k && b == n) {
    //     ans++;
    //     return;
    // }
    // if(a == k)return;
    for (int i = c; i <= n - b; i++) {
        dfs(a+1,b+i,i);
    }
}
int main() {
    cin>>n>>k;
    dfs(0,0,1);
    cout<<ans;
    return 0;
}
*/
/*
//A - 深さ優先探索
#include <bits/stdc++.h>
using namespace std;
int m,n;
char arr[505][505];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
bool flag = false;
void dfs(int a,int b) {
    if(flag == true) return;
    if(arr[a][b] == 'g') {
        flag = true;
        return;
    }
    arr[a][b]='#';
    for(int i=0;i<4;i++) {
        int x = a+dx[i];
        int y = b+dy[i];
        if(x<1 || x > n || y<1 || y > m) continue;
        if(arr[x][y] == '#') continue;
        dfs(x,y);
    }
}
int main() {
    cin>>n>>m;
    int a,b;
    for(int i= 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 's') {
                a = i;b = j;
            }
        }
    }
    dfs(a,b);
    if(flag) {
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}
*/
/*
//骑士的移动 Knight Moves
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int n,m;
int arr1[15][15];
int st[15][15];
int dx[] = {-2,-2,-1,1,2,2,1,-1};
int dy[] = {-1,1,2,2,1,-1,-2,-2};
void bfs(int a, int b) {
    queue<pair<int,int> > q;
    q.push(make_pair(a,b));
    st[a][b] = true;
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x = p.x+dx[i];
            int y = p.y+dy[i];
            if (st[x][y])continue;
            if (x<1 || x > 8 || y<1 || y > 8) continue;
            q.push(make_pair(x,y));
            arr1[x][y] = arr1[p.x][p.y]+1;
            st[x][y] = true;
        }
    }
}
int main() {
    char arr[1000][2][2];
    int n = 1;
    while ('a' <= cin.peek() && cin.peek() <= 'z') {
        cin >> arr[n][0][0] >> arr[n][0][1];
        cin >> arr[n][1][0] >> arr[n][1][1];
        n++;
        getchar();
    }
    for (int i = 1; i < n; i++) {
        bfs(arr[i][0][1]-'0',arr[i][0][0]-'a'+1);
        cout << arr1[arr[i][1][1]-'0'][arr[i][1][0]-'a'+1] << endl;
        for (int j = 0;j <=14 ;j++) {
            for(int k =0 ;k <=14 ;k++) {
                arr1[i][j] = 0;
                st[i][j] = false;
            }
        }
    }
    return 0;
}
*/
/*
//P3741 小果的键盘
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int n;
    int ans = 0;
    bool flag = false;
    cin >> n >> s;
    for (int i = 0; i < n-1; i++) {
        if(s[i] == 'V' && s[i+1] == 'K') {
            s[i] = '#';
            s[i+1] = '#';
            i++;
            ans++;
        }
    }
    for (int i = 0; i < n-1; i++) {
        if(s[i] == 'K' && s[i+1] == 'K') {
            flag = true;
            break;
        }
        if(s[i] == 'V' && s[i+1] == 'V') {
            flag = true;
            break;
        }
    }
    if(flag)cout << ans+1 << endl;
    else cout << ans << endl;
    return 0;
}
*/
/*
//B - Waiting for...
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int peoNum = 0;
    for (int i = 0; i < n; i++) {
        char A;
        int b;
        cin >> A >> b;
        switch (A) {
            case 'B': {
                if (b > peoNum) {
                    peoNum = 0;
                    cout << "YES" << endl;
                }
                else {
                    peoNum -= b;
                    cout << "NO" << endl;
                }
                continue;
            }
            case 'P': {
                peoNum += b;
            }
        }
    }
    return 0;
}
*/
/*
//A - DIY
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
void Func() {
    int v;
    int arr2[N];
    cin>>v;
    for(int i =1 ; i <=v;i++) {
        cin>>arr2[i];
    }
    sort(arr2+1,arr2+v+1);
    int m = 0x7FFFFFFF;
    int n = 0;
    for(int i =1;i<=v;i++) {
        if(arr2[i] == m) {
            arr2[n++] = arr2[i];
            m = 0x7FFFFFFF;
            continue;
        }
        m = arr2[i];
    }
    if(n < 4) {
        cout<<"NO\n";
        return;
    }
    for(int i = 0 ; i < n/2;i++) {
        for(int k = 0 ; k < 2;k++) {
            int j = n-1-i+k;
            cout<<"YES\n";
            cout<< arr2[i] << ' '<< arr2[i+1] << ' '
                << arr2[i] << ' ' << arr2[j] << ' '
                << arr2[j-1] << ' ' << arr2[i+1] << ' '
                << arr2[j-1] << ' ' << arr2[j] << '\n';
            return;
            // if(arr2[i] + arr2[j] == arr2[i+1] + arr2[j-1]) {   //x1 + y3 == x3 + y1
            //     cout<<"YES\n";
            //     cout<< arr2[i] << ' '<< arr2[i+1] << ' '
            //         << arr2[i] << ' ' << arr2[j-1] << ' '
            //         << arr2[j] << ' ' << arr2[j-1] << ' '
            //         << arr2[j] << ' ' << arr2[i+1] << '\n';
            //     return;
            // }
            // if(arr2[i] + arr2[i+1] == arr2[j] + arr2[j-1]) {
            //     cout<<"YES\n";
            //     cout<< arr2[i] << ' ' << arr2[j] << ' '
            //         << arr2[i] << ' ' << arr2[j-1] << ' '
            //         << arr2[i+1] << ' ' << arr2[j-1] << ' '
            //         << arr2[i+1] << ' ' << arr2[j] << '\n';
            //     return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i =0 ; i < n ; i++) {
        Func();
    }
    return 0;
}
*/
/*
//P1331 海战
#include <bits/stdc++.h>
int R,C;
char arr[1005][1005];
bool st[1005][1005];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int ans = 0;
using namespace std;
bool bfs(int a,int b) {
    queue<pair<int,int> > q;
    int ls[2] = {a,b};
    int rs[2] = {a,b};
    st[a][b] = true;
    ans++;
    int num = 1;
    q.push(make_pair(a,b));
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i =0;i<4;i++) {
            int qx = p.first + dx[i];
            int qy = p.second + dy[i];
            if( qx < 1 || qx > R || qy < 1 || qy > C ) continue;
            if(st[qx][qy])continue;
            if(arr[qx][qy] == '.')continue;
            st[qx][qy] = true;
            num++;
            q.push(make_pair(qx,qy));
            if(qx < ls[0] || qy < ls[1]) {
                ls[0] = qx;
                ls[1] = qy;
            }
            if(rs[0] < qx || rs[1] < qy) {
                rs[0] = qx;
                rs[1] = qy;
            }
        }
    }
    if((rs[0] - ls[0] +1 ) * (rs[1] - ls[1] +1 ) == num) {
        return true;
    }
    else {
        cout<<"Bad placement.\n";
        return false;
    }
}
int main() {
    cin>>R>>C;
    for ( int i= 1 ;i<=R;i++) {
        for(int j = 1 ;j <= C ;j++) {
            cin>>arr[i][j];
        }
    }
    for (int i = 1;i<=R;i++) {
        for (int j = 1;j<=C;j++) {
            if(!st[i][j] && arr[i][j] == '#') {
                if(bfs(i,j)) {}
                else return 0;
            }
        }
    }
    cout<< "There are " <<ans<< " ships." <<"\n";
    return 0;
}
*/
/*
//P4961 小埋与扫雷
#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[1005][1005];
int ans = 0;
bool st[1005][1005];
void dfsSpace(int a,int b) {
    queue<pair<int,int> > q;
    q.emplace(a,b);
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        if(arr[p.first][p.second] == 0) {
            //判断周边是否是0
            for(int j = -1;j <= 1;j++) {
                for(int k = -1;k <= 1;k++) {
                    int x = p.first + j;
                    int y = p.second + k;
                    if(p.first == x && p.second == y)continue;
                    if(st[x][y] == true)continue;
                    if(x < 1 || x > n || y < 1 || y > m) continue;
                    if(arr[x][y] == 0) {
                        st[x][y] = true;
                        q.emplace(x,y);
                    }
                }
            }
        }
    }
    ans++;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin>>arr[i][j];
            if(arr[i][j]==1) {
                arr[i][j]=-1;
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(arr[i][j] == -1) {
                for(int q = -1;q <= 1;q++) {
                    for(int k = -1;k <= 1;k++) {
                        int x = i + q;
                        int y = j + k;
                        if(i == x && j == y)continue;
                        if(x < 1 || x > n || y < 1 || y > m) continue;
                        if(arr[x][y] != -1) arr[x][y]++;
                    }
                }
            }
        }
    }
    //上述为判断雷及数字的
    //下列为判断3bv的
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(arr[i][j] != -1) {
                if(arr[i][j] == 0 && !st[i][j]) {
                    dfsSpace(i,j);
                }
                else if(arr[i][j] != -1) {
                    bool flag = true;
                    for(int q = -1;q <= 1;q++) {
                        for(int k = -1;k <= 1;k++) {
                            int x = i + q;
                            int y = j + k;
                            if(i == x && j == y)continue;
                            if(x < 1 || x > n || y < 1 || y > m) continue;
                            if(arr[x][y] == 0) flag = false;
                        }
                    }
                    if(flag == true) {
                        ans++;
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
//P1379 八数码难题
#include <bits/stdc++.h>
using namespace std;
string endStr = "123804765";
string start;
int swap_x[] = {-3,-1,1,3};
int main() {
    cin>>start;
    unordered_map<string,int> hash_map;
    queue<string>q;
    q.push(start);
    hash_map.insert({start,0});
    while(!q.empty()) {
        auto const str = q.front();
        int ans = hash_map[str]+1;
        if (str == endStr) {
            break;
        }
        q.pop();
        int i = 0;
        for (; i < 9; i++) {
            if (str[i] == '0') break;
        }
        for (int j = 0; j < 4; j++) {
            string str2 = str;
            int a = i+swap_x[j];
            if (a < 0 || a > 8) continue;
            if ((i == 3 && a == 2)||(i == 5 && a == 6) || (i == 2 && a == 3) ||(i == 6 && a == 5))continue;
            swap(str2[i], str2[a]);
            if (hash_map.count(str2) == 0) {
                hash_map.insert({str2, ans});
                q.push(str2);
            }
        }
    }
    cout << hash_map[endStr] << endl;
    return 0;
}
*/
/*
//P4667 [BalticOI 2011 Day1] Switch the Lamp On 电路维修
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MN = 505;
char arr[MN][MN];
bool st[MN][MN];//线的坐标
int dx[] = {-1,-1,0,0};
int dy[] = {-1,0,-1,0};
int di[] = {'\\','/','/','\\'};
int ix[] = {-1,-1,1,1};
int iy[] = {-1,1,-1,1};
int arrM[MN][MN] = {2147483647};
int n,m;
int bfs() {
    deque<pii> q;
    q.emplace_back(0, 0);
    arrM[0][0] = 0;
    //点的坐标和线的坐标有1的偏移
    while (!q.empty()) {
        pii p;
        p = q.front();
        q.pop_front();
        if (p.first == n && p.second == m) {
            return arrM[n][m];
        }
        for (int i = 0; i < 4; i++) {
            int fX = p.first + dx[i];//对p点观察周围的格子是否能走
            int fY = p.second + dy[i];
            int gX = p.first+ix[i];
            int gY = p.second+iy[i];
            if (gX < 0 || gX >n || gY < 0 || gY > m)continue;
            int w = arr[fX][fY] != di[i];
            if (arrM[p.first][p.second] +w < arrM[gX][gY]) {
                arrM[gX][gY] = arrM[p.first][p.second] + w;
                if (w) {
                    q.emplace_back(gX, gY);
                }
                else{
                    q.emplace_front(gX, gY);
                }
            }
        }
    }
    return -1;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin>>n>>m;
        for (int i =0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin>>arr[i][j];
            }
        }
        for (int i =0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                arrM[i][j] = 0xFFFFFFF;
            }
        }

        if (n+m & 1) {
            cout<< "NO SOLUTION\n";
            return 0;
        }
        cout<<bfs();
    }
    return 0;
}
*/
/*
//P1022 [NOIP2000 普及组] 计算器的改良
#include <bits/stdc++.h>
using namespace std;
bool now = false;
int main() {
    double zheng = 0;
    double xi = 0;
    char x;
    string s;
    cin >> s;
    for (int i = s.length(); i >= 0; --i) {
        char a = s[i];
        float temp = 0;
        int m = 0;
        if ('a' <= a && a <= 'z') {
            x = a;
            i--;
            while ('0' <= s[i] && s[i] <= '9' && i>=0) {
                a = s[i--];
                temp+=(a-'0')*pow(10,m++);
            }
            if (m == 0) {
                temp = 1;
            }
            if (i == -1) {
                xi-=temp;
            }
            else if (s[i] == '=' ) {
                now = true;
                xi+=temp;
            }
            else if ((s[i] == '-' && now == false) || (s[i] == '+' && now == true)) {
                xi-=temp;
            }
            else if ((s[i] == '+' && now == false) || (s[i] == '-' && now == true)) {
                xi+=temp;
            }
        }
        else if (s[i] == '=') {
            now = true;
        }
        else {
            while ('0' <= s[i] && s[i] <= '9' && i>=0) {
                a = s[i--];
                temp+=(a-'0')*pow(10,m++);
            }
            if (i == -1) {
                zheng+=temp;
            }
            else if (s[i] == '=' ) {
                now = true;
                zheng-=temp;
            }
            else if ((s[i] == '-' && now == false) || (s[i] == '+' && now == true)) {
                zheng+=temp;
            }
            else if ((s[i] == '+' && now == false) || (s[i] == '-' && now == true)) {
                zheng-=temp;
            }
        }
    }

    double endN = zheng/xi;
    if (endN == (double)-1/0) {
        endN = -endN;
    }
    printf("%c=%.3f",x ,endN);
    return 0;
}
*/
/*
//T472655 茫茫的不归路
#include <bits/stdc++.h>
using namespace std;
void Func() {
    int n,m,k,p;
    cin>>n>>m>>k>>p;
    if (m-p/n>=k)cout << "Together\n";
    else if (m*n-p>=k && m>=k)cout << "Chance\n";
    else cout << "Divide\n";
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
*/
/*
//T470314 纷飞的樱花雨
#include <bits/stdc++.h>
using namespace std;
int arr[100010];
void Func() {
    int n,k;
    cin>>n>>k;
    long long max = 0;
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        if(arr[i]>max)
            max = arr[i];
    }
    if (k<1) {
        long long ans = 0;
        max = 0;
        for(int i=0;i<n;i++) {
            if (arr[i]>max) {
                max = arr[i];
            }
            ans+=max;
        }
        cout<<ans<<endl;
    }
    else if (n == 2) {
        if ((k & 1))swap(arr[0],arr[1]);
        long long ans = 0;
        max = 0;
        for(int i=0;i<n;i++) {
            if (arr[i]>max) {
                max = arr[i];
            }
            ans+=max;
        }
        cout<<ans<<endl;
    }
    else {
        long long ans=0;

        cout<<max*n<<endl;
    }
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        Func();
    }
    return 0;
}
*/
/*
//T366125 无穷的迭代器
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        if (n == 0) cout << "NO!\n" << endl;
        else {
            n=n*2+1;
            int ans = 0;
            while (n & 1) {
                long long m = (n+1) >> 1;
                n = n*m;
                ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
*/
/*
//T532927 漫长的小纸带
#include <bits/stdc++.h>
using namespace std;
void Func() {
    int n,ans = 0;
    cin >> n;
    int arr[n+1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int l = 0, r = 0;
    while (l<=r && r<n) {
        map<int, int> mp;
        int m = r;
        for (int i = l; i<=r && r<n; i++) {
            if (mp.count(arr[i]) != 0) {
                r++;
            }
            else {
                mp[arr[i]] = arr[i];
                m++;
            }
            if (mp.size()*mp.size() <= m-l+1) {
                r = m;
            }
            else {
                while (mp.size()*mp.size() <= m-l+1) {

                }
            }
        }
        int a = mp.size()*mp.size();
        ans+=min(a,r-l+1);
        l = r+1;
        r = l;
    }
    cout << ans << endl;
}
int main() {
    Func();
    return 0;
}
*/
/*
//T472989 神奇的小江鸟
#include <bits/stdc++.h>
using namespace std;
void Func() {
    int n,k;
    cin>>n>>k;
    int arr[n][2];
    int minNum = 2147483647;
    for(int i=0;i<n;i++) {
        scanf("%d%d",&arr[i][1],&arr[i][0]);
        if (arr[i][0]<minNum) {
            minNum = arr[i][0];
        }
        arr[i][1] = arr[i][0] - arr[i][1];
    }
    minNum = min(minNum,k*2-1);
    for(int i=k;i<=minNum;i++) {
        bool flag = false;
        for (int j=0;j<n;j++) {
            if (arr[j][0]>=i && arr[j][0]%i<=arr[j][1]) {
                flag = true;
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout<<"Yes\n";
            for (int r=0;r<n;r++) {
                int ans = arr[r][0]-arr[r][1];
                cout << ans+(i-ans%i) << ' ';
            }
            cout<<"\n";
            return;
        }
    }
    cout<<"No\n";
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
*/
