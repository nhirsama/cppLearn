//  P4171 [JSOI2010] 满汉全席
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
    std::stack<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;

    SCC(int _n) {
        this->n = _n;
        adj.assign(_n, {});
        dfn.assign(_n, -1);
        low.resize(_n);
        bel.assign(_n, -1);
        cur = cnt = 0;
    }

    void add(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push(x);

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
                y = stk.top();
                bel[y] = cnt;
                stk.pop();
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
        std::string as, bs;
        std::cin >> as >> bs;
        int a = as[0] == 'm' ? 0 : 1;
        int b = bs[0] == 'm' ? 0 : 1;
        as = as.substr(1);
        bs = bs.substr(1);
        int xi = stoi(as) - 1;
        int xj = stoi(bs) - 1;
        tarjan.add(xi + n * ((a) ^ 1), xj + n * (b));
        tarjan.add(xj + n * ((b) ^ 1), xi + n * (a));
    }
    tarjan.work();
    for (int i = 0; i < n; i++) {
        if (tarjan.bel[i] == tarjan.bel[i + n]) {
            std::cout << "BAD\n";
            return;
        }
    }
    std::cout << "GOOD\n";
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
