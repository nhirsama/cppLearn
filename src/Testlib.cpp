//P1955 [NOI2015] 程序自动分析
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

struct node {
    i64 x, y, w;
};

void nhir() {
    i64 n = 0;
    cin >> n;
    vector<node> v(n + 1);
    map<i64, i32> m;
    i32 cnt = 0;

    for (i32 i = 1; i <= n; ++i) {
        i64 x, y, w;
        cin >> x >> y >> w;
        v[i] = {x, y, w};
        if (!m.count(x)) m[x] = ++cnt;
        if (!m.count(y)) m[y] = ++cnt;
    }

    vector<i32> ccb(cnt + 1);
    for (i32 i = 1; i <= cnt; ++i) ccb[i] = i;

    auto find = [&](auto self, i32 root) -> i32 {
        return ccb[root] == root ? root : ccb[root] = self(self, ccb[root]);
    };

    for (i32 i = 1; i <= n; ++i) {
        i32 x = m[v[i].x];
        i32 y = m[v[i].y];
        i32 w = v[i].w;

        if (w == 1) {
            if (find(find, x) == find(find, y + cnt)) {
                cout << "NO\n";
                return;
            }
            // 合并x和y
            i32 fx = find(find, x);
            i32 fy = find(find, y);
            ccb[fx] = fy;
            // 合并x+cnt和y+cnt
            fx = find(find, x + cnt);
            fy = find(find, y + cnt);
            ccb[fx] = fy;
        } else {
            if (find(find, x) == find(find, y)) {
                cout << "NO\n";
                return;
            }
            // 合并x和y的反集
            i32 fx = find(find, x);
            i32 fy = find(find, y + cnt);
            ccb[fx] = fy;
            // 合并y和x的反集
            fx = find(find, y);
            fy = find(find, x + cnt);
            ccb[fx] = fy;
        }
    }
    cout << "YES\n";
}

signed main() {
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        //freopen("Code.out", "w", stdout);
    }
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}