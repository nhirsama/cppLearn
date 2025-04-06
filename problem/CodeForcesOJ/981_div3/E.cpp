//E
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct UnionFind {
private:
    mutable std::vector<int> parent; // 允许 const 函数修改
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

    // 标记 find 为 const
    int find(int x) const {
        // 关键修改点
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
    i32 n;
    std::cin >> n;
    UnionFind uf(n);
    for (i32 i = 0; i < n; ++i) {
        i32 u;
        std::cin >> u;
        uf[i] = uf[--u];
    }
    std::vector<i32> cnt(n);
    i64 ans = 0;
    for (i32 i = 0; i < n; ++i) {
        cnt[uf[i]]++;
    }
    for (i32 i = 0; i < n; ++i) {
        if (cnt[i] > 2) ans += (cnt[i] - 1) / 2;
    }
    std::cout << ans << '\n';
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
