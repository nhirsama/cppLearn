//P11247 [GESP202409 六级] 算法学习
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int m, n, k, ai[N], ki[N];
vector<int> bi[N];

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> m >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ai[i];
    }
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        bi[ai[i]].push_back(a);
    }
    queue<int> q;
    for (int i = 1; i <= m; i++) {
        sort(bi[i].begin(), bi[i].end());
        q.push(i);
    }
    int u = 0, num = 0;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        bool flag = false;
        while (a == u) {
            if (flag) {
                puts("-1");
                return 0;
            }
            q.push(a);
            a = q.front();
            flag = true;
        }
        if (bi[a].empty()) {
            puts("-1");
            return 0;
        }
        ki[a] += bi[a].back();
        bi[a].pop_back();
        u = a;
        if (ki[a] < k) {
            q.push(a);
        }
        num++;
    }
    cout << num << endl;

    return 0;
}
