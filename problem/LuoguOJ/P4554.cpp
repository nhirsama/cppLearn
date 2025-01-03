#define LOCAL
//P4554 小明的游戏
//记得把文件重定向注释掉
//两个点TLE，等白天用dijkstra试试
#include <bits/stdc++.h>
using namespace std;
const int N = 505;
char g[N][N];
int money[N][N], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, n, m, x1, x2, y11, y2;
bool visited[N][N];

void dfs(int i, int j, int nowMoney) {
    if (i == x2 && j == y2) {
        money[i][j] = nowMoney;
        return;
    }
    if (money[i][j] <= nowMoney) {
        return;
    }
    money[i][j] = nowMoney;
    for (int k = 0; k < 4; k++) {
        int ix = i + dx[k], iy = j + dy[k];
        if (visited[ix][iy]) continue;
        if (ix < 0 || iy < 0 || ix >= n || iy >= m) continue;
        visited[ix][iy] = true;
        if (g[ix][iy] == g[i][j]) dfs(ix, iy, nowMoney);
        else dfs(ix, iy, nowMoney + 1);
        visited[ix][iy] = false;
    }
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
        memset(money, 0x3f, sizeof money);
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }
        scanf("%d%d%d%d", &x1, &y11, &x2, &y2);
        dfs(x1, y11, 0);
        cout << money[x2][y2] <<endl;
        cin >> n >> m;
    }


#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
