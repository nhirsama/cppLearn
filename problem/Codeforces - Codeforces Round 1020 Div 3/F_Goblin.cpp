//  F. Goblin
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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    UnionFind dsu(n * 3);
    std::vector<i64> cnt(n * 3);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cnt[i] = i;
            cnt[i + n] = 0;
            cnt[i + 2 * n] = n - i - 1;
        } else cnt[i + n] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '1' && s[i] == '0') dsu[i - 1 + n] = dsu[i];
        else if (s[i - 1] == '0' && s[i] == '1') dsu[i - 1 + 2 * n] = dsu[i + n];
        else if (s[i - 1] == '0' && s[i] == '0') dsu[i - 1] = dsu[i], dsu[i - 1 + 2 * n] = dsu[i + 2 * n];
    }
    i64 ans = 0;
    std::map<int, i64> m;
    for (int i = 0; i < 3 * n; i++) {
        m[dsu[i]] += cnt[i];
    }
    for (auto [x,y]: m) {
        ans = std::max(y, ans);
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
