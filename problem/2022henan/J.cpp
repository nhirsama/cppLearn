//
// Created by ling on 25-5-11.
//
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i32 = i64;
constexpr int N = 1000000 + 10;
int main() {
    i64 n;
    cin>>n;
    vector<i32> val(n+1);
    vector tr(n+1,vector<i32>());
    for (i32 i = 1;i<=n;i++) {
        cin>>val[i];
    }
}
// int val[N], cnt[N], mins[N], p[N];
// vector<int> g[N];
//
// void dfs(int u, int fa) {
//     cnt[u] = 1;
//     int s = val[u];
//     for (auto v : g[u]) {
//         if (v == fa) continue;
//         dfs(v, u);
//         cnt[u] += cnt[v];
//         s = min(s, val[v]);
//     }
//     mins[u] = s;
// }
//
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     int n;
//     cin >> n;
//
//     for (int i = 1; i <= n; i ++) {
//         cin >> val[i];
//         p[val[i]] = i;
//     }
//
//     for (int i = 2; i <= n; i ++) {
//         int u;
//         cin >> u;
//         g[u].push_back(i);
//         g[i].push_back(u);
//     }
//
//
//     dfs(p[0], -1);
//
//     int maxs = 0;
//     for (auto v : g[p[0]]) {
//         maxs = max(maxs, cnt[v]);
//     }
//     cout << maxs << " ";
//
//     for (int i = 1; i < n; i ++) {
//         int x = p[i];
//         if (mins[x] == i) {
//             cout << n - cnt[x] << " ";
//         } else {
//             cout << 0 << " ";
//         }
//     }
//
//     cout << n << "\n";
//
//     return 0;
// }
/*

1
0
0 1
3
0 1 2
1 1
1 2 2 3
10
9 8 7 6 5 4 0 1 2 3
1 1 2 2 3 3 4 4 5
9 9 9 9 9 0 0 0 0 0 10
*/
