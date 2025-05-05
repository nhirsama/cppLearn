//  P4782 【模板】2-SAT
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

struct SCC {
    int n;
    std::vector<std::vector<int> > adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;

    SCC() {
    }

    SCC(int _n) {
        init(_n);
    }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }

    void add(int u, int v) {
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
    int n, m;
    std::cin >> n >> m;
    SCC tarjan(n * 2);
    while (m--) {
        int xi, a, xj, b;
        std::cin >> xi >> a >> xj >> b;
        xi--, xj--;
        tarjan.add(xi + n * ((a) ^ 1), xj + n * (b));
        tarjan.add(xj + n * ((b) ^ 1), xi + n * (a));
    }
    tarjan.work();
    for (int i = 0; i < n; i++) {
        if (tarjan.bel[i] == tarjan.bel[i + n]) {
            std::cout << "IMPOSSIBLE\n";
            return;
        }
    }
    std::cout << "POSSIBLE\n";
    for (int i = 0; i < n; i++) {
        std::cout << (tarjan.bel[i] > tarjan.bel[i + n]) << ' ';
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
