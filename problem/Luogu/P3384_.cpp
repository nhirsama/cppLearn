//  P3384 【模板】重链剖分/树链剖分
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
#define endl '\n'

//
// Created by zxy15 on 25-5-27.
//
using namespace std;
int P = 998244353;
using i64 = long long;

// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}

template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Z {
    int x;

    Z(int x = 0) : x(norm(x)) {}

    Z(i64 x) : x(norm(x % P)) {}

    int val() const {
        return x;
    }

    Z operator-() const {
        return Z(norm(P - x));
    }

    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }

    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }

    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }

    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }

    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }

    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }

    friend bool operator==(const Z &lhs, const Z &rhs) {
        return lhs.x == rhs.x;
    }

    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }

    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }

    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }

    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

template<class T>
struct Segt_ {
    struct node {
        int l, r;
        T w, Min;
        T lazy;
    };
    vector<T> w;
    vector<node> t;

    Segt_(int n) {
        w.resize(n + 1);
        t.resize((n << 2) + 1);
        build(1, n);
    }

    Segt_(vector<T> in) {
        int n = in.size() - 1;
        w.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            w[i] = in[i];
        }
        t.resize((n << 2) + 1);
        build(1, n);
    }

    void pushdown(node &p, T lazy) { // 在此更新下递函数
        p.w += (p.r - p.l + 1) * lazy;
        p.Min += lazy;
        p.lazy += lazy;
    }

    void pushup(node &p, node &l, node &r) { // 在此更新上传函数
        p.w = l.w + r.w;
        //p.Min = min(l.Min, r.Min);
    }

#define GL (k << 1)
#define GR (k << 1 | 1)

    void pushdown(int k) { // 不需要动
        Z zero = 0;
        if (t[k].lazy == zero) return;
        pushdown(t[GL], t[k].lazy);
        pushdown(t[GR], t[k].lazy);
        t[k].lazy = 0;
    }

    void pushup(int k) { // 不需要动
        pushup(t[k], t[GL], t[GR]);
    }

    void build(int l, int r, int k = 1) {
        if (l == r) {
            t[k] = {l, r, w[l], w[l]};
            return;
        }
        t[k] = {l, r};
        int mid = (l + r) / 2;
        build(l, mid, GL);
        build(mid + 1, r, GR);
        pushup(k);
    }

    void modify(int l, int r, T val, int k = 1) { // 区间修改
        if (l <= t[k].l && t[k].r <= r) {
            pushdown(t[k], val);
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        if (l <= mid) modify(l, r, val, GL);
        if (mid < r) modify(l, r, val, GR);
        pushup(k);
    }

    T Min(int l, int r, int k = 1) { // 区间询问最小值
        if (l <= t[k].l && t[k].r <= r) {
            return t[k].Min;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        T ans = 1E18;
        if (l <= mid) ans = min(ans, Min(l, r, GL));
        if (mid < r) ans = min(ans, Min(l, r, GR));
        return ans;
    }

    T ask(int l, int r, int k = 1) { // 区间询问，不合并
        if (l <= t[k].l && t[k].r <= r) {
            return t[k].w;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        T ans = 0;
        if (l <= mid) ans += ask(l, r, GL);
        if (mid < r) ans += ask(l, r, GR);
        return ans;
    }

    node Ask(int l, int r, int k = 1) { // 区间合并
        if (l <= t[k].l && t[k].r <= r) {
            return t[k];
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        // 区间合并这里的if是反过来的
        if (r <= mid) return Ask(l, r, GL);
        if (mid < l) return Ask(l, r, GR);
        auto left = Ask(l, r, GL), right = Ask(l, r, GR);
        node res = {0, 0, 0, 0};
        pushup(res, left, right); // 合并left和right为新区间
        return res;
    }

    void debug(int k = 1) {
        cout << "[" << t[k].l << ", " << t[k].r << "]: ";
        cout << "w = " << t[k].w << ", ";
        cout << "Min = " << t[k].Min << ", ";
        cout << "lazy = " << t[k].lazy << ", ";
        cout << endl;
        if (t[k].l == t[k].r) return;
        debug(GL), debug(GR);
    }

#undef GL
#undef GR
};

using Segt = Segt_<int>;

struct HLD {
    int n;  // 树的节点数
    std::vector<int> siz, top, dep, parent, in, out, seq;  // siz：子树大小；top：重链顶点；dep：深度；parent：父节点；in/out：DFS 序区间；seq：DFS 序到节点的映射
    std::vector<std::vector<int>> adj;  // 邻接表
    int cur;  // 用于 DFS2 中的当前序号

    HLD() {}

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
        cur = 1;
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
        in[u] = cur++;             // 进入时间
        seq[in[u]] = u;           // 序号到节点的映射，仅供 jump 使用
        for (auto v: adj[u]) {
            // 如果是重链子节点，继承父链顶点；否则新链顶为自己
            top[v] = (v == adj[u][0] ? top[u] : v);
            dfs2(v);
        }
        out[u] = cur;              // 离开时间，仅供 isAncester 使用
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
        std::swap(u, v);  // 交换参数，统一查询
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
    i32 n, m, r;
    std::cin >> n >> m >> r >> P;
    HLD hld(n);

    std::vector<Z> num(n + 1);
    for (i32 i = 1; i <= n; i++) std::cin >> num[i];
//    for (auto &i: num) std::cin >> i;
    Segt_<Z> st(num);
    for (i32 i = 1; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        u--, v--;
        hld.addEdge(u, v);
    }
    hld.work(r - 1);
//    for (i32 i = 0; i < n; i++) {
//        st.modify(i + 1, i + 1, num[i]);
//    }
//    auto todfs = [&hld](i32 x) -> i32 {
//        return hld.in[x - 1] + 1;
//    };
    while (m--) {
        i32 op;
        cin >> op;
        if (op == 1) {
            i32 x, y;
            Z z;
            std::cin >> x >> y >> z;
            x--, y--;
//            x = todfs(x);
//            y = todfs(y);
            while (hld.top[x] != hld.top[y]) {
                if (hld.dep[hld.top[x]] < hld.dep[hld.top[y]]) swap(x, y);
                st.modify(hld.in[hld.top[x]], hld.in[x], z);
                x = hld.parent[hld.top[x]];
            }
            if (hld.dep[x] > hld.dep[y]) swap(x, y);
            st.modify(hld.in[x], hld.in[y], z);
        }
        if (op == 2) {
            i32 x, y;
            std::cin >> x >> y;
            x--, y--;
            Z res = 0;
            while (hld.top[x] != hld.top[y]) {
                if (hld.dep[hld.top[x]] < hld.dep[hld.top[y]]) swap(x, y);
                res += st.ask(hld.in[hld.top[x]], hld.in[x]);
                x = hld.parent[hld.top[x]];
            }
            if (hld.dep[x] > hld.dep[y]) swap(x, y);
            res += st.ask(hld.in[x], hld.in[y]);
            std::cout << res << '\n';
        }
        if (op == 3) {
            i32 x, y;
            std::cin >> x >> y;
            x--;
            st.modify(hld.in[x], hld.in[x] + hld.siz[x - 1] - 1, y);
        }
        if (op == 4) {
            i32 x;
            std::cin >> x;
            x--;
            std::cout << st.ask(hld.in[x], hld.in[x] + hld.siz[x - 1] - 1) << '\n';
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}