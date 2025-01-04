#define LOCAL
//P1113 杂务
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int len[N], ind[N], dp[N];
queue<int> q;
vector <int>g[N];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cin >> len[x];
        int e;
        while (cin >> e) {
            if (e == 0) {
                break;
            }
            g[e].push_back(x);
            ind[x]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            dp[i] = len[i];
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto End : g[x]) {
            dp[End] = max(dp[End], dp[x] + len[End]);
            ind[End]--;
            if (ind[End] == 0) {
                q.push(End);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}