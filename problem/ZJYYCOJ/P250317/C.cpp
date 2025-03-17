//模板
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
i32 dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

signed main() {
    IOS;
    i32 n, m;
    while (cin >> n >> m) {
        vector g(n, vector<i32>(m));
        for (i32 i = 0; i < n; i++) {
            for (i32 j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }
        queue<pii> q;
        q.push({0, 0});
        vector arr(n, vector<i32>(m,0x3f3f3f3f));
        vector st(n, vector<i32>(m));
        arr[0][0] = g[0][0];
        st[0][0] = 1;
        while (!q.empty()) {
            i32 x = q.front().x;
            i32 y = q.front().y;
            q.pop();
            for (i32 i = 0; i <= 3; i++) {
                i32 nx = x + dx[i];
                i32 ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                // if (st[nx][ny]) continue;
                if (arr[nx][ny]<=arr[x][y]+g[nx][ny]) continue;
                q.push({nx, ny});
                arr[nx][ny] = arr[x][y] + g[nx][ny];
                st[nx][ny] = 1;
            }
        }
        cout << arr[n - 1][m - 1] << endl;
    }

    return 0;
}
