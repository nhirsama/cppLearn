#include<bits/stdc++.h>
using namespace std;

void dfs(int a, int b, vector<vector<int> > &g, vector<int> &bf) {
    if (a == -1)return;
    bf[a] = b;
    for (auto j: g[a]) {
        dfs(j, b + 1, g, bf);
    }
}

int main() {
    int root = 0;
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    vector<int> bf(n + 1);
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        if (u == -1) {
            root = i;
            continue;
        }
        g[u].push_back(i);
    }
    dfs(root, 1, g, bf);
    int maxb = 0;
    for (int i = 1; i <= n; i++) {
        if (bf[i] > maxb) {
            maxb = bf[i];
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (bf[i] == maxb) {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << maxb << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1)cout << ' ';
    }
}
