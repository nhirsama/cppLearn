#include <bits/stdc++.h>
using namespace std;

struct augment_path {
    vector<set<int> > notg;
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
        notg.resize(n);
        res = 0;
        dfn = 0;
    }

    void add(int from, int to) {
        assert(0 <= from && from < n && 0 <= to && to < m);
        notg[from].insert(to);
    }

    bool dfs(int v) {
        vis[v] = dfn;
        for (int i = 1; i <= n; i++) {
            if (!notg[v].contains(i)) {
                if (pb[i] == -1) {
                    pb[i] = v;
                    pa[v] = i;
                    return true;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (vis[pb[i]] != dfn && dfs(pb[i])) {
                pa[v] = i;
                pb[i] = v;
                return true;
            }
        }
        return false;
    }

    int solve() {
        while (true) {
            dfn++;
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
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
    std::cin >> n;
    augment_path xyl(n + 1, n + 1);
    for (int i = 1; i <= n; i++) {
        int p;
        std::cin >> p;
        for (int j = 0; j < p; j++) {
            int tt;
            std::cin >> tt;
            xyl.add(i, tt);
        }
    }
    auto t = xyl.solve();
    if (t == n) {
        for (int i = 1; i <= n; i++) {
            std::cout << xyl.pa[i] << ' ';
        }
    } else cout << -1 << '\n';
}
