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
