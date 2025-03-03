#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
vector<int> g[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k;
    cin >> k;
    auto find = [](auto self, int p, vector<int> &root) -> int {
        return root[p] == p ? p : root[p] = self(self, root[p], root);
    };
    while (k--) {
        int np;
        cin >> np;
        vector<int> root(n + 1), st(n + 1);
        for (int i = 1; i <= n; i++) root[i] = i;
        for (int i = 1; i <= np; i++) {
            int x;
            cin >> x;
            st[x] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (st[i]) continue;
            for (auto j: g[i]) {
                if (st[j]) continue;
                root[find(find, j, root)] = root[find(find, i, root)];
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (root[i] != i) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
