#define LOCAL
//P3385 【模板】负环
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;

const int N  = 2e3+10,M = 3e3+10;
// vector<pair<int,int>> g;
// struct edge {
//     int u, v, w;
// };
void Func() {
    int n, m;
    cin >> n >> m;
    int dist[n+10];
    bool st[n + 5];
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    int num[n + 5];
    memset(num, 0, sizeof(num));
    vector<pair<int, int> > g[n + 5];
    dist[1] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        // g[i] = (edge){u, v, w};
        if (w>=0) {
            g[v].push_back(make_pair(u, w));
        }
        g[u].push_back(make_pair(v, w));
    }
    queue<int> q;
    q.push(1);
    st[1] = true;

    while (!q.empty()) {
        int x = q.front();
        if (num[x] > n) break;
        q.pop();
        st[x] = false;
        for (auto i: g[x]) {
            if (dist[i.first] > dist[x] + i.second) {
                dist[i.first] = dist[x] + i.second;
                if (!st[i.first]) {
                    q.push(i.first);
                    num[i.first]++;
                }
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     bool flag = false;
    //     for (int j = 0; j < m; j++) {
    //         if (dist[g[j].u] > dist[g[j].v] + g[j].w) {
    //             dist[g[j].u] = dist[g[j].v] + g[j].w;
    //             flag = true;
    //         }
    //     }
    //     if (flag) num++;
    // }
    for (int i = 1; i <= n; i++) {
        if (num[i] > n) {
            puts("YES");
            return;
        }
    }
    puts("NO");
}

int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P3385_1.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        Func();
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
