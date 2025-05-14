//
// Created by zxy15 on 25-5-14.
//
#include <bits/stdc++.h>
using i32 = long long;
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
    void add(int u, int v) { adj[u].push_back(v); }

    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push(x);
        for (auto y: adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) low[x] = std::min(low[x], dfn[y]);
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
        for (int i = 0; i < n; i++) if (dfn[i] == -1) dfs(i);
        return bel;
    }
};
int main() {
    i32 n;
    std::cin>>n;
    SCC tarjan(n * 2+2);
    std::vector<bool> B(n+1),C(n+1);
    for (i32 i = 1;i<n;i++) {
        i32 t;
        std::cin>>t;
        if (t) B[i] = true;
        else C[i] = true;
    }
    for (i32 i = 2;i<=n;i++) {
        for (i32 j = i+1;j<=n;j++) {
            int xi = i, a, xj = j, b = B[i];
            std::cin >>a ;
            xi--, xj--;
            tarjan.add(xi + n * ((a) ^ 1), xj + n * (b));
            tarjan.add(xj + n * ((b) ^ 1), xi + n * (a));
        }
    }
    tarjan.work();
    for (int i = 1; i <= n; i++) {
        if (tarjan.bel[i] == tarjan.bel[i + n]) {
            std::cout << "0 0\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << (tarjan.bel[i] > tarjan.bel[i + n]) << ' ';
    }
}