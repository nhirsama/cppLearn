//  E. One-Way Reform
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
bool __main__ = true;

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

signed main() {
    if (__main__) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int T;
        std::cin >> T;
        __main__ = false;
        return main();
    }
    i32 n, m;
    if (std::cin >> n >> m) {
        std::vector<bool> vis(n);
        std::vector g(n, std::vector<i32>(n));
        std::vector<i32> id(n);
        UnionFind uf(n);
        i32 ansss = 0;
        for (i32 i = 0; i < m; i++) {
            i32 u, v;
            std::cin >> u >> v;
            u--, v--;
            g[u][v]++;
            g[v][u]++;
            // g[u].push_back(v);
            // g[v].push_back(u);
            id[v]++;
            id[u]++;
            uf[v] = uf[u];
        }
        std::vector st(n, std::vector<bool>(n));
        std::map<i32, std::vector<i32> > mp;
        for (i32 i = 0; i < n; i++) {
            if (id[i] & 1) {
                mp[uf[i]].push_back(i);
            } else ansss++;
        }
        for (auto &[_, vv]: mp) {
            for (i32 i = 0; i < vv.size(); i += 2) {
                g[vv[i]][vv[i + 1]] += 100;
                g[vv[i + 1]][vv[i]] += 100;
                // g[vv[i]].push_back(vv[i + 1]);
                // g[vv[i + 1]].push_back(vv[i]);
                //std::cout << vv[i] << ' ' << vv[i + 1] << ' ';
            }
            //std::cout << endl;
        }
        std::vector<i32> cnt(n);
        std::vector<i32> ans;
        auto dfs = [&](this auto &&self, i32 u) -> void {
            vis[u] = true;
            for (; cnt[u] < n;) {
                if (st[u][cnt[u]]) {
                    cnt[u]++;
                    continue;
                }
                st[cnt[u]][u] = true;
                st[u][cnt[u]] = true;
                self(g[u][cnt[u]++]);
            }
            ans.push_back(u);
        };
        std::cout << ansss << endl;
        for (i32 i = 0; i < n; i++) {
            if (vis[i]) continue;
            dfs(i);
            for (auto j: ans) {
                std::cout << j << ' ';
            }
            std::cout << endl;
            for (i32 j = 0; j < ans.size() - 1; j++) {
                if (id[ans[j]] % 2 != 1 && id[ans[j + 1] % 2 != 1]) {
                    std::cout << ans[j] + 1 << ' ' << ans[j + 1] + 1 << endl;
                }
            }
            ans.clear();
        }
        return main();
    }
    return 0;
}
