//  P3379 【模板】最近公共祖先（LCA）
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'

template<typename T>
struct HLD {
    T n;
    std::vector<std::vector<T>> tree;
    std::vector<T> fa, deep, son, siz, top;

    HLD(T _n) {
        n = _n;
        tree.assign(n);
        fa.assign(n);
        deep.assign(n);
        son.assign(n);
        siz.assign(n);
        top.assign(n);
    }

    void add(T _u, T _v) {
        tree[_u].push_back(_v);
        tree[_v].push_back(_u);
    }

    void dfs1(T u, T f) {
        fa[u] = f, deep[u] = deep[f] + 1, siz[u] = 1;
        for (auto v: tree[u]) {
            if (v == f) continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if (siz[son[u]] < siz[v]) son[u] = v;
        }
    }

    void build() {

    }
};

void nhir() {

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}