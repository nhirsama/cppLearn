#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    long long sum = 0;
    std::vector g(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int ii = 1; ii <= n; ii++) {
                for (int ji = 1; ji <= m; ji++) {
                    sum += std::max(std::abs(i - ii), std::abs(j - ji));
                }
            }
            std::cout << g[i][j] * sum << " \n"[j == m];
            sum = 0;
        }
    }
}
