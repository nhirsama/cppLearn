//  D - RGB Coloring 2
//  下午3:28
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

struct UnionFind {
private:
    mutable std::vector<int> parent;
    std::vector<int> rank;

    struct ElementProxy {
        UnionFind &uf;
        int index;

        operator int() const { return uf.find(index); }

        void operator=(const ElementProxy &other) {
            uf.merge(index, other.index);
        }
    };

public:
    explicit UnionFind(int n) : parent(n), rank(n, 1) {
        //for (int i = 0; i < n; ++i) parent[i] = i;
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) const {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            if (rank[rootX] == rank[rootY]) ++rank[rootY];
        }
    }

    ElementProxy operator[](int x) {
        return {*this, x};
    }

    // const 版本调用 const find
    int operator[](int x) const {
        return find(x);
    }
};

void nhir() {
    int n, m;
    std::cin >> n >> m;
    UnionFind dsu(n);
    std::vector g(n, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        dsu[u] = dsu[v];
    }
    int64 cnt = 0;
    std::vector<int> vis(n);
    std::vector<int> sd(n);

    auto dfs = [&](auto &&dfs, int u, int s) -> void {
        int base = 0;
        for (auto v: g[u]) {
            base |= vis[v];
        }
        if (base & vis[u]) return;
        for (auto v: g[u]) {
            if (vis[v]) continue;
            for (int i = 1; i < 0x1000; i <<= 1) {
                vis[v] = i;
                dfs(dfs, v, s + 1);
                vis[v] = 0;
            }
        }
        if (s >= sd[dsu[u]]) cnt++;
//        bool f = false;
//        for (auto v: g[u]) {
//            if (vis[v] == vis[u]) return;
//            if (vis[v] != -1) continue;
//            f = true;
//            for (int i = 0; i < 3; i++) {
//                if (i == c) continue;
//                dfs(dfs, v, i);
//            }
//            vis[v] = false;
//        }
//        if (f) cnt++;
    };
    for (int i = 0; i < n; i++) {
        sd[dsu[i]]++;
    }
    std::vector<bool> visf(n);
    for (int i = 0; i < n; i++) {
        if (visf[dsu[i]]) continue;
        visf[dsu[i]] = true;
        for (int j = 1; j < 0x1000; j <<= 1) {
            vis[i] = j;
            dfs(dfs, i, 1);
            vis[i] = 0;
        }
    }
    std::cout << cnt * 3 << endl;
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