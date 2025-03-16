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

struct augment_path {
    vector<vector<int> > g;
    vector<int> pa; // 匹配
    vector<int> pb;
    vector<int> vis; // 访问
    int n, m; // 两个点集中的顶点数量
    int dfn; // 时间戳记
    int res; // 匹配数

    augment_path(int _n, int _m) : n(_n), m(_m) {
        assert(0 <= n && 0 <= m);
        pa = vector<int>(n, -1);
        pb = vector<int>(m, -1);
        vis = vector<int>(n);
        g.resize(n);
        res = 0;
        dfn = 0;
    }

    void add(int from, int to) {
        assert(0 <= from && from < n && 0 <= to && to < m);
        g[from].push_back(to);
    }

    bool dfs(int v) {
        vis[v] = dfn;
        for (int u: g[v]) {
            if (pb[u] == -1) {
                pb[u] = v;
                pa[v] = u;
                return true;
            }
        }
        for (int u: g[v]) {
            if (vis[pb[u]] != dfn && dfs(pb[u])) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
    }

    int solve() {
        while (true) {
            dfn++;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (pa[i] == -1 && dfs(i)) {
                    cnt++;
                }
            }
            if (cnt == 0) {
                break;
            }
            res += cnt;
        }
        return res;
    }
};


signed main() {
    IOS;
    i64 n, ans = 0;
    cin >> n;
    vector<pii> r(n + 1), b(n + 1);
    augment_path xyl(n, n);
    for (int i = 1; i <= n; i++) {
        cin >> r[i].x >> r[i].y;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i].x >> b[i].y;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (r[i].x < b[j].x && r[i].y < b[j].y) {
                xyl.add(i-1, j-1);
            }
        }
    }
    // sort(all1(r));
    // sort(all1(b));
    // function<void(int,int)>dfs=[&](int u,int cnt) {
    //     if (u==n+1) {
    //         ans=max(ans,cnt);
    //         return;
    //     }
    //     for (int i = 1; i <=n; ++i) {
    //         if (!st[i]&&r[u].x<b[i].x&&r[u].y<b[i].y) {
    //             st[i] = true;
    //             dfs(u+1,cnt+1);
    //             st[i] = false;
    //         }
    //     }
    //     dfs(u+1,cnt);
    // };
    // dfs(1,0);
    cout << xyl.solve() << endl;
    return 0;
}
