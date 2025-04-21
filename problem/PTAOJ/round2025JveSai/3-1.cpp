#include <bits/stdc++.h>
constexpr int inf = 0x3f3f3f3f;

int main() {
    int b, n, m, k;
    std::cin >> b >> n >> m >> k;
    std::vector g(n, std::vector<int>(n, inf));
    std::vector xq(n, std::vector<int>(n, 0));
    for (int i = 1; i <= m; i++) {
        int u, v, w, z;
        std::cin >> u >> v >> w >> z;
        u--, v--;
        g[u][v] = w;
        g[v][u] = w;
        xq[u][v] = z;
        xq[v][u] = z;
    }
    for (int kk = 0; kk < n; kk++) {
        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < n; jj++) {
                if (g[ii][jj] > g[ii][kk] + g[kk][jj]) {
                    g[ii][jj] = g[ii][kk] + g[kk][jj];
                    xq[ii][jj] = xq[ii][kk] + xq[kk][jj];
                } else if (g[ii][jj] == g[ii][kk] + g[kk][jj]) {
                    xq[ii][jj] = std::max(xq[ii][jj], xq[ii][kk] + xq[kk][jj]);
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int q;
        std::cin >> q;
        q--;
        int xqq = 0;
        std::vector<int> ans, xqans;
        for (int j = 0; j < n; j++) {
            if (j == q) continue;
            if (g[q][j] <= b) {
                ans.push_back(j + 1);
                if (xq[q][j] == xqq) {
                    xqans.push_back(j + 1);
                } else if (xq[q][j] > xqq) {
                    xqq = xq[q][j];
                    xqans.clear();
                    xqans.push_back(j + 1);
                }
            }
        }
        std::sort(ans.begin(), ans.end());
        std::sort(xqans.begin(), xqans.end());
        if (ans.size() == 0) {
            std::cout << "T_T\n";
        } else {
            for (int j = 0; j < ans.size(); j++) {
                std::cout << ans[j] << " \n"[j == ans.size() - 1];
            }
            for (int j = 0; j < xqans.size(); j++) {
                std::cout << xqans[j] << " \n"[j == xqans.size() - 1];
            }
        }
    }
}
