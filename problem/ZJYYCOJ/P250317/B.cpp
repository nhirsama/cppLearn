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
#define int long long
i32 dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

signed main() {
    IOS;
    i32 n, m;
    while (cin >> n >> m) {
        queue<pii> q;
        q.push({});
        vector arr(n + 1, vector<i32>(m + 1));
        vector st(n + 1, vector<i32>(m + 1));
        for (i32 i = 1; i <= n; i++) {
            for (i32 j = 1; j <= m; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 2) {
                    q.push({i, j});
                    st[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            i32 x = q.front().x;
            i32 y = q.front().y;
            q.pop();
            for (i32 i = 0; i <= 3; i++) {
                i32 nx = x + dx[i];
                i32 ny = y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (st[nx][ny]) continue;
                if (arr[nx][ny] == 0) continue;
                q.push({nx, ny});
                st[nx][ny] = st[x][y] + 1;
                arr[nx][ny] = 2;
            }
        }
        i32 ans = 0;
        bool flag = true;
        for (i32 i = 1; i <= n; i++) {
            for (auto j = 1; j <= m; j++) {
                if (arr[i][j] == 1) {
                    flag = false;
                    break;
                }
                ans = max(ans, st[i][j]);
            }
        }
        if (flag)cout << ans - 1 << endl;
        else cout << -1 << endl;
    }

    return 0;
}
