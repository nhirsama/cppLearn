//  P3388 【模板】割点（割顶）
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct V_DCC {
    int n;
    std::vector<std::vector<int> > ver, col;
    std::vector<int> dfn, low, S;
    int now, cnt;
    std::vector<bool> point; // 记录是否为割点

    V_DCC(int n) : n(n) {
        ver.resize(n + 1);
        dfn.resize(n + 1);
        low.resize(n + 1);
        col.resize(2 * n + 1);
        point.resize(n + 1);
        S.clear();
        cnt = now = 0;
    }

    void add(int x, int y) {
        if (x == y) return; // 手动去除重边
        ver[x].push_back(y);
        ver[y].push_back(x);
    }

    void tarjan(int x, bool root) {
        int rd = 0;
        low[x] = dfn[x] = ++now;
        for (auto i: ver[x]) {
            if (!dfn[i]) {
                tarjan(i, false);
                low[x] = std::min(low[x], low[i]);
                if (low[i] >= dfn[x] && !root) point[x] = true;
                if (root) rd++;
            } else low[x] = std::min(low[x], dfn[i]);
        }
        if (root && rd >= 2) {
            point[x] = true;
            return;
        }
    }

    std::pair<int, std::vector<std::vector<int> > > rebuild() {
        // [新图的顶点数量, 新图]
        work();
        std::vector<std::vector<int> > adj(cnt + 1);
        for (int i = 1; i <= cnt; i++) {
            if (!col[i].size()) {
                // 注意，孤立点也是 V-DCC
                continue;
            }
            for (auto j: col[i]) {
                if (point[j]) {
                    // 如果 j 是割点
                    adj[i].push_back(point[j]);
                    adj[point[j]].push_back(i);
                }
            }
        }
        return {cnt, adj};
    }

    void work() {
        for (int i = 1; i <= n; ++i) {
            // 避免图不连通
            if (!dfn[i]) {
                tarjan(i, true);
            }
        }
    }
};

void nhir() {
    int n, m;
    std::cin >> n >> m;
    V_DCC dcc(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        dcc.add(u, v);
    }
    dcc.work();
    int cnt = 0;
    std::vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (dcc.point[i]) cnt++, v.push_back(i);
    }
    std::cout << cnt << endl;
    for (auto i: v) {
        std::cout << i << ' ';
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
