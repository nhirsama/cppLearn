#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector vis1(n + 10, vector<bool>(m + 10));
    vector vis2(n + 10, vector<bool>(m + 10));
    std::vector qwq(n, std::vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            qwq[i][j] = (vis1[i][j] && !vis2[i][j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}