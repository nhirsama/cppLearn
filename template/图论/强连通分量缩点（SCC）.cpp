/**   强连通分量缩点（SCC）
 *    其中dfn表示dfs序，low用与强连通分量判断，bel用于表示强联通分量，cut表示强联通分量个数。
 *    使用0-index。
 *    当且仅当 bel_i == bel_j 时表示点i与点j在同一个强连通分量中。
**/
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
