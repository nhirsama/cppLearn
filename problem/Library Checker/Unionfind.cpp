//  Unionfind  并查集
//  上午2:48
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Library Checker"};

template<class Container = std::vector<int>>
class DisjointSetUnion {
public:
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;

    static_assert(std::is_signed_v<value_type>,
                  "Container::value_type must be signed");

    Container parent;
    size_type counter = 0;

    DisjointSetUnion(size_type n = 0) : parent(n, -1) {}

    value_type root(value_type n) noexcept {
        if (parent[n] < 0) return n;
        return parent[n] = root(parent[n]); // 路径压缩
    }

    bool same(size_type a, size_type b) {
        return root(static_cast<value_type>(a)) == root(static_cast<value_type>(b));
    }

    void merge(size_type a, size_type b) {
        value_type ar = root(static_cast<value_type>(a));
        value_type br = root(static_cast<value_type>(b));
        if (ar == br) return;
        if (parent[ar] < parent[br]) { // 按秩合并
            parent[ar] += parent[br];
            parent[br] = ar;
        } else {
            parent[br] += parent[ar];
            parent[ar] = br;
        }
    }
};

template<class Container = std::vector<int>>
using DSU = DisjointSetUnion<Container>;


void nhir() {
    int n, q;
    std::cin >> n >> q;
    DSU<> dsu(n);
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 0) {
            int u, v;
            std::cin >> u >> v;
            dsu.merge(u, v);
        } else {
            int u, v;
            std::cin >> u >> v;
            std::cout << (dsu.same(u, v)) << endl;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
//        std::cin >> T;
        while (T--) nhir();
    return 0;
}