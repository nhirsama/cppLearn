//  B. Find Marble
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

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
    i32 n, s, t;
    std::cin >> n >> s >> t;
    UnionFind dsu(n);
    std::vector<i32> v(n);
    s--, t--;
    for (auto &i: v)std::cin >> i, i--;
    for (i32 i = 0; i < n; i++) {
        dsu[i] = dsu[v[i]];
    }
    if (dsu[s] == dsu[t]) {
        std::vector<bool> vis(n);
        i32 cnt = 0;
        auto bfs = [&](i32 u) {
            while (!vis[u]) {
                if (u == t) return;
                vis[u] = true;
                cnt++;
                u = v[u];
            }
        };
        bfs(s);
        std::cout << cnt << endl;
    } else {
        std::cout << -1 << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}