//  Two Coins
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
using arr2 = std::array<i32, 2>;

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
    i32 n, m;
    std::cin >> n >> m;
//    std::vector g(n, std::vector<arr2>());
    std::vector<std::array<i32, 3>> adj(m);
    while (m--) {
        i32 u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[m] = {u, v, w};
//        g[u].push_back({v, w});
        //g[v].push_back({u, w});
    }
    i32 base = 0;
    i32 ans = 0;
    for (i32 bit = 29; bit >= 0; bit--) {
        UnionFind uf(n);
        i32 baset = base | (1 << bit);
        for (auto &[u, v, w]: adj) {
            if ((w & baset) == 0) uf[u] = uf[v];
        }
//        for (i32 i = 0; i < n; i++) {
//            for (auto &[v, w]: g[i]) {
//                if ((w & baset) == 0)
//                    uf[i] = uf[v];
//            }
//        }
        if (uf[0] == uf[n - 1]) {
            base = baset;
        } else {
            ans |= (1 << bit);
        }
    }
    std::cout << ans << endl;
//    auto dijkstra = [&](i32 s = 0) {
//        using pii = std::pair<i32, i32>;
//        std::vector<i32> dij_dis(n, 0b111111111111111111111111111111111111ll);
//        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;
//        q.emplace(0, s);
//        dij_dis[s] = 0;
//        std::vector<bool> dij_vis(n);
//        while (!q.empty()) {
//            i32 u = q.top().second;
//            q.pop();
//            if (dij_vis[u]) continue;
//            dij_vis[u] = true;
//            for (auto [v, w]: g[u]) {
//                if (dij_dis[v] >= (dij_dis[u] | w)) {
//                    dij_dis[v] = dij_dis[u] | w;
//                    q.emplace(dij_dis[v], v);
//                }
//            }
//        }
//        return dij_dis;
//    };
//    auto dist = dijkstra();
//    std::cout << dist[n - 1] << endl;
//    i32 base = 0, ans = 0;
//    auto bfs = [&](i32 base) -> bool {
//        std::vector<bool> vis(n);
//        std::queue<i32> q;
//        q.push(0);
//        while (!q.empty()) {
//            auto u = q.front();
//            q.pop();
//
//            if (u == n - 1) {
//                return true;
//            }
//            for (auto &[v, w]: g[u]) {
//                if (vis[v]) continue;
//                if (((w & base) == 0)) {
//                    q.push(v);
//                    vis[u] = true;
//                }
//            }
//        }
//        return false;
//    };
//    std::vector<bool> vis(n);
//    auto dfs = [&](auto &&dfs, i32 u, i32 &base) -> bool {
//        if (u == n - 1) {
//            return true;
//        }
//        for (auto &[v, w]: g[u]) {
//            if (vis[v]) continue;
//            if ((w & base) == 0) {
//                vis[v] = true;
//                if (dfs(dfs, v, base)) {
//                    vis[v] = false;
//                    return true;
//                }
//                vis[v] = false;
//            }
//        }
//        return false;
//    };
//    for (i32 bit = 30; bit >= 0; bit--) {
//        i32 baset = (1ll << bit) | base;
//        if (bfs(baset)) {
//            base |= 1ll << bit;
//        } else ans |= 1ll << bit;
//    }
//    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}