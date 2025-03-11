#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
char g[N][N];
int h, w;
int ans;
int st[N][N];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
vector<pair<int, int> > tp[27];
pair<int, int> be, en;

void dfs(int a, int b) {
    queue<pair<int, int> > q;
    q.emplace(a, b);
    st[a][b] = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || ny <= 0 || nx > h || ny > w || g[nx][ny] == '#' || st[nx][ny] != -1) continue;
            q.emplace(nx, ny);
            st[nx][ny] = st[x][y] + 1;
        }
        int xx = g[x][y] - 'a';
        if (xx >= 0 && xx <= 26) {
            for (auto &k: tp[xx]) {
                int tpx = k.first;
                int tpy = k.second;
                if (st[tpx][tpy] != -1) continue;
                if (x != tpx || y != tpy) {
                    q.emplace(tpx, tpy);
                    st[tpx][tpy] = st[x][y] + 1;
                }
            }
            tp[xx].clear();
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie (0);
    cin >> h >> w;
    int flag = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            cin >> g[i][j];
            st[i][j] = -1;
            if (flag<2) {
                if (g[i][j] == 'S') {
                    be.first = i;
                    be.second = j;
                    flag++;
                }
                if (g[i][j] == 'G') {
                    en.first = i;
                    en.second = j;
                    flag++;
                }
            }
            int aa = g[i][j] - 'a';
            if (aa >= 0 && aa <= 26) {
                tp[aa].emplace_back(i, j);
            }
        }
    dfs(be.first, be.second);
    cout << st[en.first][en.second] << endl;
    return 0;
}
