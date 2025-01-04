#define LOCAL
//P4554 小明的游戏
//记得把文件重定向注释掉
//两个点TLE，等白天用dijkstra试试
#include <bits/stdc++.h>
using namespace std;
const int N = 505;
char g[N][N];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, n, m, x1, x2, y11, y2;
bool visited[N][N];

int dfs(int i, int j) {
    deque<pair<pair<int,int>,int> > q;
    q.push_back(make_pair(make_pair(i, j),0));
    visited[i][j] = true;
    while (!q.empty()) {
        pair<int,int> p = q.front().first;
        int mon = q.front().second;
        q.pop_front();
        if (p.first == x2 && p.second == y2) {
            return mon;
        }
        for (int k = 0; k < 4; k++) {
            int ix = p.first + dx[k];
            int iy = p.second + dy[k];
            if (visited[ix][iy]) continue;
            if (ix < 0 || iy < 0 || ix >= n || iy >= m) continue;
            visited[ix][iy] = true;
            if(g[ix][iy]==g[p.first][p.second]) {
                q.push_front(make_pair(make_pair(ix, iy), mon));
            }
            else {
                q.push_back(make_pair(make_pair(ix, iy), mon+1));
            }
        }
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m;
    while (n != 0 && m != 0) {
        memset(g, 0, sizeof(g));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }
        scanf("%d%d%d%d", &x1, &y11, &x2, &y2);
        int t = dfs(x1, y11);
        cout << t <<endl;
        cin >> n >> m;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
