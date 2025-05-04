//  A. Hongcow Builds A Nation
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
    i32 n, m, k;
    std::cin >> n >> m >> k;
    std::vector g(n + 1, std::vector<int>());
    std::set<int> zf;
    for (int i = 0; i < k; i++) {
        i32 x;
        std::cin >> x;
        zf.insert(x);
    }
    UnionFind uf(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        uf[u] = uf[v];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    i32 nonecnt = 0;
    std::vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[uf[i]]++;
    }
    std::vector<bool> vis(n + 1);
    for (auto i: zf) {
        vis[uf[i]] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && cnt[i]) nonecnt += cnt[i], cnt[i] = 0;
    }
    i32 ans = 0;
    //std::cout<<nonecnt<<endl;
    *std::ranges::max_element(cnt) += nonecnt;
    for (auto i: cnt) {
        if (i) {
            ans += i * i - i;
        }
    }
    for (auto &i: g) {
        ans -= i.size();
    }
    std::cout << ans / 2 << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
