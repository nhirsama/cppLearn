//P1111 修复公路
#include <bits/stdc++.h>
using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

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
        for (int i = 0; i < n; ++i) parent[i] = i;
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

struct edge {
    int x, y;
    int t;
};

void nhir() {
    int n, m;
    std::cin >> n >> m;
    std::vector<edge> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i].x >> a[i].y >> a[i].t;
    }
    std::sort(all(a), [](const edge &a, const edge &b) { return a.t < b.t; });
    UnionFind f(n + 1);
    int max = 0;
    for (auto [x,y,t]: a) {
        if (f[x] != f[y]) {
            max = t;
            f[x] = f[y];
        }
    }
    int root = f[1];
    for (int i = 1; i <= n; i++) {
        if (f[i] != root) {
            std::cout << -1 << endl;
            return;
        }
    }
    std::cout << max << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }

    while (T--) nhir();
    return 0;
}
