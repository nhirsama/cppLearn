//  P2598 [ZJOI2009] 狼和羊的故事
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

constexpr int inf = 1E9;

template<class T>
struct MaxFlow {
    struct _Edge {
        int to;
        T cap;

        _Edge(int to, T cap) : to(to), cap(cap) {
        }
    };

    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int> > g;
    std::vector<int> cur, h;

    MaxFlow() {
    }

    MaxFlow(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }

    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i: g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }

    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }

    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }

    T flow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }

    std::vector<bool> minCut() {
        std::vector<bool> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = (h[i] != -1);
        }
        return c;
    }

    struct Edge {
        int from;
        int to;
        T cap;
        T flow;
    };

    std::vector<Edge> edges() {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void nhir() {
    int n, m;
    std::cin >> n >> m;
    MaxFlow<i32> flow(n * m + 2);
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < m; j++) {
            i32 t;
            std::cin >> t;
            if (t == 1) {
                flow.addEdge(0, i * m + j + 1, inf);
            } else if (t == 2) {
                flow.addEdge(i * m + j + 1, n * m + 1, inf);
            }
            for (i32 k = 0; k < 4; k++) {
                int ix = i + dx[k];
                int iy = j + dy[k];
                if (ix < 0 || iy < 0 || ix >= n || iy >= m) continue;
                flow.addEdge(i * m + j + 1, ix * m + iy + 1, 1);
            }
        }
    }
    flow.flow(0, n * m + 1);
    auto cur = flow.minCut();
    int ans = 0;
    for (auto &e: flow.edges()) {
        if (cur[e.from] && !cur[e.to]) {
            ans++;
        }
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
