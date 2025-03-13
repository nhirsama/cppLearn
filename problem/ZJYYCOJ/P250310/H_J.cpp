#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int n;
    while (cin >> n) {
        vector<string> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        vector arr2(n, vector<int>(n));
        vector arr3(n, vector<int>(n));
        int cnth = 1;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == '.')arr2[i][j] = cnth, flag = true;
                else if (flag)cnth++, flag = false;
            }
            if (flag)cnth++;
        }
        int cntl = 1;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (arr[j][i] == '.')arr3[j][i] = cntl, flag = true;
                else if (flag)cntl++, flag = false;
            }
            if (flag)cntl++;
        }
        augment_path xyl(cnth, cntl);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == '.') {
                    xyl.add(arr2[i][j], arr3[i][j]);
                }
            }
        }
        int ans = xyl.solve();
        cout << ans << endl;
    }

    return 0;
}
