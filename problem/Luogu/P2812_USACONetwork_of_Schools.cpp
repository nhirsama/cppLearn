//  P2812 校园网络【[USACO]Network of Schools加强版】
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct SCC {
    int n;
    std::vector<std::vector<int> > adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;

    SCC() {
    }

    SCC(int n) {
        init(n);
    }

    void init(int __n) {
        this->n = __n;
        adj.assign(__n, {});
        dfn.assign(__n, -1);
        low.resize(__n);
        bel.assign(__n, -1);
        stk.clear();
        cur = cnt = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);

        for (auto y: adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }

        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }

    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

void nhir() {
    int n;
    std::cin >> n;
    SCC tarjan(n);

    for (int i = 0; i < n; i++) {
        int u;
        while (std::cin >> u) {
            if (!u) break;
            tarjan.addEdge(i, --u);
        }
    }
    tarjan.work();
    std::vector<int> din(tarjan.cnt), dout(tarjan.cnt);
    std::vector<std::set<int> > vs(tarjan.cnt);
    for (int i = 0; i < n; i++) {
        for (int j: tarjan.adj[i]) {
            int u = tarjan.bel[i];
            int v = tarjan.bel[j];
            if (u != v) {
                if (vs[u].find(v) == vs[u].end()) {
                    din[v]++;
                    dout[u]++;
                    vs[u].insert(v);
                }
            }
        }
    }
    if (tarjan.cnt == 1) {
        std::cout << "1\n0" << endl;
        return;
    } else {
        int dinc = std::count(din.begin(), din.end(), 0);
        int doutc = std::count(dout.begin(), dout.end(), 0);
        std::cout << dinc << endl;
        std::cout << std::max(doutc, dinc);
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
