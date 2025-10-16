//  Museum Acceptance
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

//struct UnionFind {
//private:
//    mutable std::vector<int> parent;
//    std::vector<int> rank;
//
//    struct ElementProxy {
//        UnionFind &uf;
//        int index;
//
//        operator int() const { return uf.find(index); }
//
//        void operator=(const ElementProxy &other) {
//            uf.merge(index, other.index);
//        }
//    };
//
//public:
//    explicit UnionFind(int n) : parent(n), rank(n, 1) {
//        //for (int i = 0; i < n; ++i) parent[i] = i;
//        std::iota(parent.begin(), parent.end(), 0);
//    }
//
//    int find(int x) const {
//        return parent[x] == x ? x : (parent[x] = find(parent[x]));
//    }
//
//    void merge(int x, int y) {
//        int rootX = find(x);
//        int rootY = find(y);
//        if (rootX == rootY) return;
//
//        if (rank[rootX] > rank[rootY]) {
//            parent[rootY] = rootX;
//        } else {
//            parent[rootX] = rootY;
//            if (rank[rootX] == rank[rootY]) ++rank[rootY];
//        }
//    }
//
//    ElementProxy operator[](int x) {
//        return {*this, x};
//    }
//
//    // const 版本调用 const find
//    int operator[](int x) const {
//        return find(x);
//    }
//};

void nhir() {
    i32 n;
    std::cin >> n;
//    UnionFind uf(n);
    std::vector g(n, std::vector<int>());
//    std::vector<i32> ans(n);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        g[i] = std::vector<int>(a);
        for (int j = 0; j < a; j++) {
            std::cin >> g[i][j];
            g[i][j]--;
        }
//        std::ranges::sort(g[i]);
    }
    std::set<std::array<int, 2>> se;
    std::stack<int> be;
    std::vector<int> ans(n);
    auto dfs = [&](auto &&self, int u, int f) {
        int t = 0;
        if (f == -1) {
            t = 0;
        } else {
            for (; t < g[u].size(); t++) {
                if (g[u][t] == f) break;
            }
            t = (t + 1) % int(g[u].size());
        }
        int v = g[u][t];
        if (se.find({u, v}) != se.end()) {
            std::set<std::array<int, 2>> path;
            for (auto [x, y]: se) {
                if (x > y) std::swap(x, y);
                path.insert({x, y});
            }
            while (!be.empty()) {
                int ttt = be.top();
                be.pop();
//                std::cout << ttt << endl;
                ans[ttt] = path.size();
            }
//            for (auto [x, y]: se) {
//                std::cout << std::format("{} {} |", x + 1, y + 1);
//            }
//            std::cout << endl;
            return;
        }
        se.insert({u, v});
//        std::cout << std::format("{} {} | ", u + 1, v + 1);

        if (t == 0) {
            be.push(u);
        }
        self(self, v, u);
    };
    for (int i = 0; i < n; i++) {
        if (!ans[i]) {
            se.clear();
            dfs(dfs, i, -1);
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << endl;
    }
//    std::vector<std::array<bool, 3>> vis(n);
//    std::set<std::array<int, 2>> vis;
//    std::vector<bool> st(n);
//    i32 f = 0;
//    auto dfs = [&](auto &&self, int u, int f, int r, int d) -> void {
//        i32 t = 0;
//        for (; t < int(g[u].size());) {
//            if (g[u][t] == f) break;
//            t++;
//        }
//        int v = g[u][(t + 1) % (int(g[u].size()))];
//        if (vis.find({u, v}) != vis.end()) {
//            ans[uf[r]] = d;
//            return;
//        } else {
//            if (v == g[u][0]) {
//                uf[r] = uf[u];
//            }
//            vis.insert({u, v});
////            if (v == r) d--;
//            if (vis.find({v, u}) != vis.end()) d--;
//            self(self, v, u, r, d + 1);
//        }

//            for (int i = 0; i < int(g[u].size()); i++) {
//                if (g[u][i] <= f) continue;
//                if (vis[u][i]) break;
//                vis[u][i] = true;
//                dfs(g[u][i], u, r + 1);
//            }
//    };
//    for (int i = 0; i < n; i++) {
//        if (ans[uf[i]]) continue;
//        else {
//            vis = std::set<std::array<int, 2>>();
//            dfs(dfs, g[i][0], g[i].back(), i, 0);
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        std::cout << ans[uf[i]] << enld;
//    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}