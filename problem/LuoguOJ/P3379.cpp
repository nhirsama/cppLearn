//P3379 【模板】最近公共祖先（LCA）
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct HLD {
    int n, idx;
    std::vector<std::vector<int> > ver;
    std::vector<int> siz, dep;
    std::vector<int> top, son, parent;

    HLD(int n) {
        this->n = n;
        ver.resize(n + 1);
        siz.resize(n + 1);
        dep.resize(n + 1);
        top.resize(n + 1);
        son.resize(n + 1);
        parent.resize(n + 1);
    }

    void add(int x, int y) {
        // 建立双向边
        ver[x].push_back(y);
        ver[y].push_back(x);
    }

    void dfs1(int x) {
        siz[x] = 1;
        dep[x] = dep[parent[x]] + 1;
        for (auto y: ver[x]) {
            if (y == parent[x]) continue;
            parent[y] = x;
            dfs1(y);
            siz[x] += siz[y];
            if (siz[y] > siz[son[x]]) {
                son[x] = y;
            }
        }
    }

    void dfs2(int x, int up) {
        top[x] = up;
        if (son[x]) dfs2(son[x], up);
        for (auto y: ver[x]) {
            if (y == parent[x] || y == son[x]) continue;
            dfs2(y, y);
        }
    }

    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] > dep[top[y]]) {
                x = parent[top[x]];
            } else {
                y = parent[top[y]];
            }
        }
        return dep[x] < dep[y] ? x : y;
    }

    int clac(int x, int y) {
        // 查询两点间距离
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    }

    void work(int root = 1) {
        // 在此初始化
        dfs1(root);
        dfs2(root, root);
    }
};

void nhir() {
    i32 n, m, s;
    std::cin >> n >> m >> s;
    HLD lca(n);
    for (i32 i = 1; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        lca.add(u, v);
    }
    lca.work(s);
    for (i32 i = 0; i < m; i++) {
        i32 a, b;
        std::cin >> a >> b;
        std::cout << lca.lca(a, b) << endl;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }

    while (T--) nhir();
    return 0;
}
