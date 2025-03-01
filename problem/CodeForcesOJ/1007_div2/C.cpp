#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

void Solve() {
    int n, st, en;
    cin >> n >> st >> en;
    vector g(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector ans(n + 1, vector<int>());
    auto bfs = [&](auto self, int v, int dist, int u) -> void {
        ans[dist].push_back(v);
        for (auto i: g[v]) {
            if (i == u) continue;
            self(self, i, dist + 1, v);
        }
    };
    bfs(bfs, en, 1, 0);
    for (int i = n; i; i--) {
        for (auto j: ans[i]) cout << j space;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
