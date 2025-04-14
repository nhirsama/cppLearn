//  E - Reachable Set
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
    i32 n,m;
    std::cin>>n>>m;
    std::vector g(n+1,std::vector<i32>());
    for(i32 i = 0;i<m;i++){
        i32 u,v;
        std::cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<bool> st(n+1);
    std::set<i32> era,root;
    UnionFind uf(n+1);
    i32 cnt = 0;
    for(i32 i = 1;i<=n;i++){
        cnt++;
        for(auto &v:g[i]){
            if(v<i){
                if(uf[v] !=uf[i]) uf[v] = uf[i],cnt--;
            }
            else era.insert(v);
        }
        era.erase(i);
        if(cnt>1){
            std::cout<< -1 <<endl;
        }
        else std::cout<<era.size()<<endl;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}