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
