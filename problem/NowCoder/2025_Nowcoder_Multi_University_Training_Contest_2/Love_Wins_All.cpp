//  Love Wins All
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 998244353;
constexpr char endl = '\n';
constexpr char enld = '\n';
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

i32 power(i32 a, i64 b, i32 p) {
    i32 res = 1;
    for (; b; b /= 2, a = a * a % p) {
        if (b % 2) {
            res = res * a % p;
        }
    }
    return res;
}

void nhir() {
    i32 n;
    std::cin >> n;
    UnionFind uf(n);
    std::vector<i32> v(n);
    for (i32 &i: v) {
        std::cin >> i;
        i--;
    }
    for (i32 i = 0; i < n; i++) {
        uf[i] = uf[v[i]];
    }
    std::map<i32, i32> m;
    for (i32 i = 0; i < n; i++) {
        m[uf[i]]++;
    }
    std::vector<i32> odd, even, alleven;
    for (auto &[_, i]: m) {
        if (i & 1) odd.push_back(i);
        else {
            if (i > 2) even.push_back(i);
            alleven.push_back(i);
        }
    }
    if (odd.size() > 2) {
        std::cout << 0 << endl;
        return;
    } else if (odd.size() == 2) {
        i32 ans = 1;
        ans = (odd[0] * odd[1] % mod * power(2, i32(even.size()), mod)) % mod;
        std::cout << ans % mod << endl;
        return;
    } else {
        i32 ans = 0;
        for (auto i: alleven) {
            if (i == 2) {
                ans = (ans + power(2, i32(even.size()), mod)) % mod;
            } else {
                ans = ans + i * i / 4 % mod * power(2, i32(even.size() - 1), mod) % mod;
            }
        }
        std::cout << ans % mod << enld;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}