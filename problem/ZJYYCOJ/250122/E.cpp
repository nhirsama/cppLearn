#define LOCAL
//E. 点击连接
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<pair<int, long long> > g[N];
int n, m;
bool st[N];
long long dist[N];

bool dfs(int i) {
    int cnt = 1;
    st[i] = true;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto j: g[t]) {
            int a = j.first;
            if (st[a]) {
                continue;
            }
            st[a] = true;
            q.push(a);
            cnt++;
        }
        if (cnt >= n) {
            return true;
        }
    }
    if (cnt >= n) return true;
    return false;
}

long long prim() {
    long long res = 0;
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[1] = 0;
    for (int i = 0; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if ((!st[j]) && (t == -1 || dist[j] < dist[t])) t = j;
        }
        if (dist[t] == 0x3f3f3f3f3f3f3f3f) return -1;
        if (t == -1 || st[t]) break;
        st[t] = true;
        res += dist[t];
        for (auto k: g[t]) {
            if (dist[k.first] >  k.second)
                dist[k.first] = k.second;
        }
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {

        long long k, c;
        cin >> k >> c;
        vector<int> a(k);
        for (int j = 0; j < k; j++) {
            int z;
            scanf("%d", &z);
            a.push_back(z);
        }
        for (auto j: a)
            for (auto z: a)
                g[j].push_back(make_pair(z, c));
    }
        int t = prim();
        cout << t << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
