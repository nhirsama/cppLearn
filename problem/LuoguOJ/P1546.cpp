#define LOCAL
//P1546 [USACO3.1] 最短网络 Agri-Net
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int a, b, w;

    bool operator<(const edge &e) const {
        return w < e.w;
    }
} edge[20005];
int ans, n, root[20005];

int find(int x) {
    return x == root[x] ? x : root[x] = find(root[x]);
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            scanf("%d", &a);
            if (j > i) {
                edge[cnt].w = a;
                edge[cnt].a = i;
                edge[cnt++].b = j;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        root[i] = i;
    }
    sort(edge, edge + cnt);
    int dista = 0;
    for (int i = 0; i < cnt; i++) {
        if (find(edge[i].a) != find(edge[i].b)) {
            ans += edge[i].w;
            root[find(edge[i].a)] = find(edge[i].b);
            dista++;
            if (dista == n - 1) break;
        }
    }
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
