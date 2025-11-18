//  Amazing Sets (amazing)
//  下午2:04
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

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


void nhir() {
    int n;
    std::cin >> n;
    std::vector<int64> w(n);
    SCC g(n);
    std::vector<int> d(n);
    for (auto &i: w)std::cin >> i;
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g.add(u, v);
        d[v]++;
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == 0) r = i;
    }
    int m;
    std::cin >> m;
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g.add(u, v);
    }
    auto bel = g.work();
    std::vector<int64> nw(g.cnt);
    std::vector t(g.cnt, std::vector<int>());
    //    std::vector invt(g.cnt, std::vector<int>());
    //    d = std::vector<int>(g.cnt);
    for (int i = 0; i < n; i++) {
        nw[bel[i]] += w[i];
        for (auto v: g.adj[i]) {
            if (bel[i] == bel[v]) continue;
            t[bel[i]].push_back(bel[v]);
            //            invt[bel[v]].push_back(bel[i]);
        }
    }
    n = g.cnt;
    r = bel[r];
    for (int i = 0; i < n; i++) {
        std::ranges::sort(t[i]);
        //        std::ranges::sort(invt[i]);
        t[i].erase(std::unique(t[i].begin(), t[i].end()), t[i].end());
        //        invt[i].erase(std::unique(invt[i].begin(), invt[i].end()), invt[i].end());
        //        d[i] = t[i].size();
    }
    std::vector dp(n, std::vector<bool>());
    auto dfs = [&](auto &&self, int u, int f) -> void {
        dp[u] = {1};
        for (auto v: t[u]) {
            if (v == f) continue;
            self(self, v, u);
            nw[u] += nw[v];
            int lu = dp[u].size();
            int lv = dp[v].size();
            std::vector<bool> tmp(lu + lv + 1);
            for (int i = 0; i < lu; i++) {
                if (dp[u][i]) {
                    for (int j = 0; j < lv; j++) {
                        if (dp[v][j]) tmp[i + j] = true;
                    }
                }
            }
            std::swap(dp[u], tmp);
            //            for (int i = 4000; ~i; i--) {
            //                for (int j = 0; j <= i; j++) {
            //                    dp[u][i] = dp[u][i] | (dp[u][i - j] & dp[v][j]);
            //                }
            //            }
            //            for (int i = 4000; ~i; i--) {
            //                for (int j = 4000 - i; ~j; j--) {
            //                    dp[u][i + j] = dp[u][i + j] | (dp[u][i] & dp[v][j]);
            //                }
            //            }
        }
        dp[u].resize(nw[u] + 1);
        dp[u][nw[u]] = true;
    };
    dfs(dfs, r, -1);
    int ans = 0;
    for (auto i: dp[r]) {
        ans += i;
    }
    std::cout << ans << endl;
    //    std::vector<std::set<int>> vs(n);
    /*
        std::queue<int> tup;
        for (int i = 0; i < n; i++) {
            if (d[i] == 0) {
                tup.push(i);
            }
        }

        while (!tup.empty()) {
            int u = tup.front();
            tup.pop();
            for (int v: invt[u]) {
                dp[u] += dp[v];
                if (--d[v] == 0) {
                    tup.push(v);
                }
            }
        }
        */
    /*
    while (!tup.empty()) {
        int u = tup.front();
        tup.pop();

        for (int v: invt[u]) {
            vs[v].insert(vs[u].begin(), vs[u].end());
            if (--d[v] == 0) {
                tup.push(v);
            }
        }
    }
    std::set<int64> ans;
    ans.insert(0);
    for (int i = 0; i < n; i++) {
        int64 res = 0;
        for (int64 j: vs[i]) {
            res += dp[j];
        }
        ans.insert(res);
    }

    std::cout << ans.size() << endl;
    /*
    /*
    for (auto i: d)std::cout << i << endl;
    std::queue<int> tup;
    for (int i = 0; i < g.cnt; i++) {
        if (d[i] == 0) {
            tup.push(i);
        }
    }
    while (!tup.empty()) {
        int u = tup.front();
        tup.pop();
        std::cout << u << enld;
        for (int v: invt[u]) {
            dp[v] += dp[u];
            if (--d[v] == 0) {
                tup.push(v);
            }
        }
    }
    std::set<int64> ans;
    for (auto i: dp) {
        ans.insert(i);
    }
    std::cout << ans.size() + 1 << endl;
     */
    /*
    std::vector<int64> dp(g.cur);
    auto dfs = [&](auto &&self, int u, int f) -> void {
        dp[u] += neww[u];
        for (auto v: t[u]) {
            if (v == f) continue;
            self(self, v, u);
            dp[u] += dp[v];
        }
    };
    dfs(dfs, r, -1);
    std::set<int64> ans;
    for (auto i: dp) {
        ans.insert(i);
    }
    std::cout << ans.size() + 1 << endl;
     */
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