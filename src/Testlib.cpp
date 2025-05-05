#include <bits/stdc++.h>
using namespace std;

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

struct SCC {
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    int cur, cnt;

    SCC() {}

    SCC(int _n) {
        init(_n);
    }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.assign(n, 0);
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
        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = min(low[x], low[y]);
            } else if (bel[y] == -1) {  // y 仍在栈中
                low[x] = min(low[x], dfn[y]);
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

    vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};
int literal(int x, int a, int n) {
    return x + ((a) ? n : 0);
}
int neg(int x, int a, int n) {
    return x + ((a) ? 0 : n);
}
void nhir() {
    int n, m;
    cin >> n >> m;
    // 每个变量有两个节点：编号 [0, n-1] 表示变量为 false，[n, 2*n-1] 表示变量为 true
    SCC tarjan(n * 2);
    while (m--) {
        int a, va, b, vb;
        cin >> a >> va >> b >> vb;
        a--, b--;  // 变量下标变为 0 基
        if (va && vb) { // a, b 都真，-a -> b, -b -> a
            tarjan.add(a+n,b);
            tarjan.add(b+n,a);
        } else if (!va && vb) { // a 假 b 真，a -> b, -b -> -a
            tarjan.add(a,b);
            tarjan.add(b+n,a+n);
        } else if (va && !vb) { // a 真 b 假，-a -> -b, b -> a
            tarjan.add(a+n,b+n);
            tarjan.add(b,a);
        } else if (!va && !vb) {
            // a, b 都假，a -> -b, b -> -a
            tarjan.add(a,b+n);
            tarjan.add(b,a+n);
        }
    }
    vector<int> bel = tarjan.work();
    // 检查每个变量及其否定是否出现在同一个 SCC 中
    for (int i = 0; i < n; i++) {
        if (bel[i] == bel[i + n]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << "POSSIBLE\n";
    // 输出每个变量的赋值，通常可令：(bel[i] < bel[i+n]) 表示 true，这里仅作输出参考
    for (int i = 0; i < n; i++) {
        cout << (bel[i] < bel[i + n]) << ' ';
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--)
        nhir();
    return 0;
}
