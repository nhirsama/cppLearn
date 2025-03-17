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

signed main() {
    i32 T;
    i32 n, m;
    while (cin >> n >> m) {
        vector<i32> v(n + 1);
        for (i32 p = 1; p <= n; p++) {
            cin >> v[p];
        }
        i32 dx[] = {-1, 1};
        bool flag = false;
        auto bfs = [&](i32 i) {
            vector<i32> st(n + 1);
            queue<i32> q;
            q.push(i);
            while (!q.empty()) {
                i32 t = q.front();
                q.pop();
                if (v[t] == 0 && st[t]) {
                    flag = true;
                    return;
                }
                for (i32 j: dx) {
                    i32 nx = t + v[t] * j;
                    if (nx < 1 || nx > n) continue;
                    if (st[nx]) continue;
                    q.push(nx);
                    st[nx] = 1;
                }
            }
        };
        bfs(m+1);
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
