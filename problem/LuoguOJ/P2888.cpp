#define LOCAL
//P2888 [USACO07NOV] Cow Hurdles S
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int n, m, t;
const int N = 305;
int g[N][N];

void floyd() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                g[j][k] = min(g[j][k],max(g[j][i],g[i][k]));
                //g[j][k] = min(g[j][i], g[i][k]);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m >> t;
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = min(g[x][y], z);
    }
    floyd();
    while (t--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (g[x][y] == 0x3f3f3f3f) {
            puts("-1");
        }
        else {
            cout << g[x][y] << endl;
        }
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
