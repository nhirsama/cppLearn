#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int g[N][N];
string s;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, h, w, n, m;
int cnt = 1;

void bfs(int i, int j) {
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    g[i][j] = cnt + 48;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ix = p.first + dx[k];
            int iy = p.second + dy[k];
            if (g[ix][iy] == '.') {
                q.push(make_pair(ix, iy));
                g[ix][iy] = cnt + 48;
            }
        }
    }
}
bool run(int i, int j) {
    int dx = i;
    int dy = j;
    for (int k = 0; k < s.size(); k++) {

        if (s[k] == 'L') dy--;
        if (s[k] == 'R') dy++;
        if (s[k] == 'U') dx--;
        if (s[k] == 'D') dx++;
        if (g[i][j] != g[dx][dy]) return false;
    }
    return true;
}
int main() {
    int ans = 0;
    cin >> h >> w >> n;
    cin >> s;
    for (int i = 1; i <= h; i++) {
        string t;
        cin >> t;
        m = t.size();
        for (int j = 1; j <= t.size(); j++) {
            g[i][j] = t[j - 1];
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '.') {
                bfs(i, j);
                cnt++;
                if (cnt == '#')cnt++;
            }
        }
    }
    int dx = 0, dy = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L') dy--;
        if (s[i] == 'R') dy++;
        if (s[i] == 'U') dx--;
        if (s[i] == 'D') dx++;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= m; j++) {
            if (i+dx <=0 || j+dy<=0 || i+dx > h||j+dy >m) continue;
            if ((g[i][j] == g[i + dx][j + dy]) && (g[i][j] != '#')) {
                if (run(i,j)) ans++;
            }
        }
    }
    cout << ans << endl;
    // for (int i = 1; i <= h; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << (char)g[i][j];
    //     }
    //     cout << endl;
    // }
    return 0;
}
