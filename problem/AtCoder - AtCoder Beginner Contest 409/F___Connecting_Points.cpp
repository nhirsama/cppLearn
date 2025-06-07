//  F - Connecting Points
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
    i32 n, q;
    std::cin >> n >> q;
    std::vector<std::array<i32, 2> > point;
    for (i32 i = 0; i < n; i++) {
        i32 a, b;
        std::cin >> a >> b;
        point.push_back({a, b});
    }
    std::vector<std::array<i32, 3> > query;
    for (i32 i = 0; i < q; i++) {
        i32 a;
        std::cin >> a;
        if (a == 1) {
            i32 b, c;
            std::cin >> b >> c;
            point.push_back({b, c});
            query.push_back({a, b, c});
        } else if (a == 2) {
            query.push_back({a, 0, 0});
        } else {
            i32 b, c;
            std::cin >> b >> c;
            query.push_back({a, b, c});
        }
    }
    std::vector<std::array<i32, 3> > edge;
    for (i32 i = 0; i < point.size(); i++) {
        for (i32 j = i + 1; j < point.size(); j++) {
            i32 d = abs(point[i][0] - point[j][0]) + abs(point[i][1] - point[j][1]);
            edge.push_back({i, j, d});
        }
    }
    std::ranges::sort(edge, [](auto a, auto b) { return a[2] < b[2]; });
    UnionFind dsu(point.size());
    i32 p = 0;
    i32 now = n;
    i32 t = n;
    for (auto &[a,b,c]: query) {
        if (a == 1) {
            now++;
            t++;
        } else if (a == 2) {
            if (t == 1) {
                std::cout << -1 << endl;
            } else {
                // while (p < edge.size() && dsu[edge[p][0]] == dsu[edge[p][1]]) p++;
                while (p < edge.size() && (edge[p][0] >= now || edge[p][1] >= now || dsu.find(edge[p][0]) == dsu.
                                           find(edge[p][1]))) p++;
                i32 k = edge[p][2];
                while (p < edge.size() && edge[p][2] == k) {
                    if (dsu[edge[p][0]] != dsu[edge[p][1]]) {
                        dsu[edge[p][0]] = dsu[edge[p][1]];
                        t--;
                    }
                    p++;
                }
                std::cout << k << "\n";
            }
        } else {
            std::cout << (dsu[b - 1] == dsu[c - 1] ? "Yes\n" : "No\n");
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
