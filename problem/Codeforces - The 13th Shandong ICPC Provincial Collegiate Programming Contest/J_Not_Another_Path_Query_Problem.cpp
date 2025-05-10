//  J. Not Another Path Query Problem
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

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
    i32 n, m, q, V;
    std::cin >> n >> m >> q >> V;
    //std::vector g(n, std::vector<std::array<i32, 2> >());
    std::vector<std::array<i32, 3> > edge(m);
    // for (i32 i = 0; i < m; i++) {
    //     i32 u, v, w;
    //     std::cin >> u >> v >> w;
    //     g[u].push_back({v,w});
    //     g[v].push_back({u,w});
    // }
    for (auto &[u,v,w]: edge) std::cin >> u >> v >> w;
    std::vector<i32> masks;
    masks.push_back(V);
    // for (int bit = 0; bit < 60; ++bit) {
    //     if (!(V >> bit & 1))
    //         masks.push_back(V & -1LL << bit | 1LL << bit);
    // }
    for (i32 i = 0; i < 60; i++) {
        if ((V & ((1ll << i))) == 0) {
            masks.push_back(((V >> i) << i) | (1ll << i));
        }
    }
    std::vector<UnionFind> uf(masks.size(), UnionFind(n + 1));
    for (i32 i = 0; i < masks.size(); i++) {
        for (auto [u,v,w]: edge) {
            if ((w & masks[i]) == masks[i]) {
                uf[i][u] = uf[i][v];
            }
        }
    }
    while (q--) {
        i32 u, v;
        std::cin >> u >> v;
        bool ok = false;
        for (auto &i: uf) {
            if (i[u] == i[v]) {
                ok = true;
                break;
            }
        }
        std::cout << (ok ? "Yes\n" : "No\n");
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
