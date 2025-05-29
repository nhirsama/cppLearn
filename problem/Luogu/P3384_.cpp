//  P3384 【模板】重链剖分/树链剖分
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
#define endl '\n'

//
// Created by zxy15 on 25-5-27.
//
int P = 998244353;


struct msg {
    i32 lazy;
    i32 sum;
};

template<typename T>
class segtree {
private:
    int n;
    std::vector<msg> segmsg;

    void merge(int node) {
        segmsg[node].sum = segmsg[2 * node + 1].sum + segmsg[2 * node + 2].sum;
    }

    void pushdown(int node, int len) {
        auto &[lazy, sum] = segmsg[node];
        sum += lazy * len;
        if (node * 2 + 1 < 4 * n) {
            segmsg[2 * node + 1].lazy += lazy;
            segmsg[2 * node + 2].lazy += lazy;
        }
        lazy = 0;
    }

    void build(int node, int l, int r, std::vector<T> &nums) {
        if (l == r) {
            segmsg[node] = {0, nums[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, nums);
        build(2 * node + 2, mid + 1, r, nums);
        merge(node);
    }

    void add(int node, int l, int r, int ql, int qr, T val) {
        pushdown(node, r - l + 1);
        if (ql <= l && r <= qr) {
            segmsg[node].lazy += val;
            pushdown(node, r - l + 1);
            return;
        }
        if (r < ql || qr < l) return;
        int mid = (l + r) / 2;
        add(node * 2 + 1, l, mid, ql, qr, val);
        add(node * 2 + 2, mid + 1, r, ql, qr, val);
        merge(node);
    }

    T getsum(int node, int l, int r, int ql, int qr) {
        pushdown(node, r - l + 1);
        if (ql <= l && r <= qr) return segmsg[node].sum;
        if (r < ql || qr < l) return 0;
        int mid = (l + r) / 2;
        return getsum(2 * node + 1, l, mid, ql, qr) + getsum(2 * node + 2, mid + 1, r, ql, qr);
    }

public:
    segtree() = default;

    segtree(std::vector<T> &nums) {
        n = nums.size();
        segmsg.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    void build(std::vector<T> &nums) {
        n = nums.size();
        segmsg.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    void add(int l, int r, T val) {
        add(0, 0, n - 1, l, r, val);
    }

    T getsum(int l, int r) {
        return getsum(0, 0, n - 1, l, r);
    }
};

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;

    HLD() {}

    HLD(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
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

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }

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

    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v: adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }

    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }

    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }

        int d = dep[u] - k;

        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }

        return seq[in[u] - dep[u] + d];
    }

    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }

    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }

    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }

    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

void nhir() {
    i32 n, m, r;
    std::cin >> n >> m >> r >> P;
    HLD hld(n);
    std::vector<int> num(n);

    for (auto &i: num) std::cin >> i;
    std::vector<i32> init(n);
    for (i32 i = 1; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        u--, v--;
        hld.addEdge(u, v);
    }
    hld.work(r - 1);
    for (i32 i = 0; i < n; i++) {
        init[hld.in[i]] = num[i];
    }
    segtree<i32> st(init);
    while (m--) {
        i32 op;
        std::cin >> op;
        if (op == 1) {
            i32 x, y;
            i32 z;
            std::cin >> x >> y >> z;
            x--, y--;
            while (hld.top[x] != hld.top[y]) {
                if (hld.in[hld.top[x]] < hld.in[hld.top[y]]) std::swap(x, y);
                st.add(hld.in[hld.top[x]], hld.in[x], z);
                x = hld.parent[hld.top[x]];
            }
            if (hld.in[x] > hld.in[y]) std::swap(x, y);
            st.add(hld.in[x], hld.in[y], z);
            //st.debug();
        }
        if (op == 2) {
            i32 x, y;
            std::cin >> x >> y;
            x--, y--;
            i32 res = 0;
            while (hld.top[x] != hld.top[y]) {
                if (hld.in[hld.top[x]] < hld.in[hld.top[y]]) std::swap(x, y);
                res += st.getsum(hld.in[hld.top[x]], hld.in[x]);
                x = hld.parent[hld.top[x]];
            }
            if (hld.in[x] > hld.in[y]) std::swap(x, y);
            res += st.getsum(hld.in[x], hld.in[y]);
            std::cout << res % P << '\n';
        }
        if (op == 3) {
            i32 x, y;
            std::cin >> x >> y;
            x--;
            st.add(hld.in[x], hld.out[x] - 1, y);
        }
        if (op == 4) {
            i32 x;
            std::cin >> x;
            x--;
            std::cout << st.getsum(hld.in[x], hld.out[x] - 1) % P << '\n';
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