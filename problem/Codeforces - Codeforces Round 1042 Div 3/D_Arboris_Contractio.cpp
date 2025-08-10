//  D. Arboris Contractio
//  23:02
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

struct HLD {
    int n; // 树的节点数
    std::vector<int> siz, top, dep, parent, in, out, seq;
    // siz：子树大小；top：重链顶点；dep：深度；parent：父节点；in/out：DFS 序区间；seq：DFS 序到节点的映射
    std::vector<std::vector<int> > adj; // 邻接表
    int cur; // 用于 DFS2 中的当前序号

    HLD() {
    }

    HLD(int n) {
        init(n);
    }

    // 初始化结构，设置大小并清空邻接表
    void init(int _n) {
        n = _n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }

    // 添加无向边
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 入口函数：执行 dfs1 和 dfs2，完成所有预处理
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }

    // dfs1：计算 siz、dep、parent，并将重链子节点放到 adj[u][0]
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        siz[u] = 1;
        for (auto &v: adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }

    // dfs2：计算 in、out、seq，以及 top 信息
    void dfs2(int u) {
        in[u] = cur++; // 进入时间
        seq[in[u]] = u; // 序号到节点的映射，仅供 jump 使用
        for (auto v: adj[u]) {
            // 如果是重链子节点，继承父链顶点；否则新链顶为自己
            top[v] = (v == adj[u][0] ? top[u] : v);
            dfs2(v);
        }
        out[u] = cur; // 离开时间，仅供 isAncester 使用
    }

    // 计算 u 与 v 的最近公共祖先（LCA）——非树链剖分功能
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            // 跳至深度较小链的父节点
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }

    // 计算 u 到 v 的距离（边数）——非树链剖分功能
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    // 从 u 向上跳 k 步，返回目标节点；若深度不足返回 -1——非树链剖分功能
    int jump(int u, int k) {
        if (dep[u] < k) return -1;
        int d = dep[u] - k;
        // 跳整条重链
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        // 在同一条链内直接定位
        return seq[in[u] - dep[u] + d];
    }

    // 判断 u 是否为 v 的祖先（包括自身）——非树链剖分功能
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }

    // 在以 v 为根的树中，返回 u 的父节点——非树链剖分功能
    int rootedParent(int u, int v) {
        std::swap(u, v); // 交换参数，统一查询
        if (u == v) return u;
        if (!isAncester(u, v)) {
            return parent[u];
        }
        // u 在 v 子树内，找到分界重链上的节点
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }

    // 在以 v 为根的树中，返回 v 的子树大小——非树链剖分功能
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        // 排除向 u 方向的子树部分
        return n - siz[rootedParent(u, v)];
    }

    // 在以 c 为根时，求 a 和 b 的 LCA：非树链剖分功能
    int rootedLca(int a, int b, int c) {
        // 利用异或性质计算重根后的 LCA
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

void nhir() {
    int n;
    std::cin >> n;
    // HLD t(n);
    std::vector t(n, std::vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        // t.addEdge(u, v);
        t[u].push_back(v);
        t[v].push_back(u);
    }
    if (n == 2) {
        std::cout << 0 << enld;
        return;
    }
    std::vector<int> ny(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        // ny[i] = t[i].size();
        for (auto v: t[i]) {
            if (t[v].size() == 1) ny[i]++;
        }
        sum += ny[i];
    }
    int ans = 0;
    int cnt = 0;
    auto dfs = [&](this auto &&self, int u, int f)-> void {
        if (t[u].size() == 1) {
            cnt++;
            return;
        }
        for (auto v: t[u]) {
            if (v == f) continue;
            self(v, u);
        }
    };
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (ny[r] < ny[i])r = i;
    }
    std::cout << sum - ny[r] << enld;
    // std::vector<int> po;
    // po.push_back(r);
    // for (int i = 0; i < n; i++) {
    //     if (t[r].size() < t[i].size()) {
    //         r = i;
    //         po = std::vector<int>();
    //         po.push_back(r);
    //     } else if (t[r].size() == t[i].size()) {
    //         po.push_back(i);
    //     }
    // }
    // ans = 0x3f3f3f3f;
    // for (auto r: po) {
    //     int anss = 0;
    //     for (auto u: t[r]) {
    //         if (t[u].size() == 1) continue;
    //         dfs(u, r);
    //         anss += cnt;
    //         cnt = 0;
    //     }
    //     ans = std::min(anss, ans);
    // }
    // std::cout << ans << enld;
    // t.work();
    // std::cout << t.adj.size() << endl;
    // int ans = 0;
    // std::vector<int> c(n);
    // [&](this auto &&dfs, int u, int f, int cl)-> void {
    //     int tt = 0;
    //     for (auto v: t[u]) {
    //         if (v == f) continue;
    //         ans++;
    //         dfs(v, u, cl + tt);
    //     }
    //     ans--;
    // }(0, -1, 0);
    // for (auto i: t) {
    //     ans += std::max(0, int(i.size()) - 2);
    // }
    // std::cout << ans << enld;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}
