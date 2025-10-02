//  U614486 所以什么是生成排列
//  12:04
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};

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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for (auto &i: v) std::cin >> i, i--;
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        uf[i] = uf[v[i]];
    }
    std::map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[uf[i]]++;
    }
    if (n - m.size() > k) {
        std::cout << "NO\n";
    } else {
        if ((k - (n - m.size())) & 1) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
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
