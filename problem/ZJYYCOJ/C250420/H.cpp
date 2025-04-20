//模板
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

void nhir() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> num(n + 1);
    UnionFind f(n + 2);
    for (int i = 1;i<=n;i++) {
        std::cin>>num[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        f[u] = f[v];
    }
    std::vector<int> cnt(n + 1);
    std::vector<i64> numm(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[f[i]]++;
        numm[f[i]] += num[i];
    }
    for (int i = 1; i <= n; i++) {
        double ans = 1.0 * numm[f[i]] / cnt[f[i]];
        printf("%.6f\n", ans);
    }
}

signed main() {
    //IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
