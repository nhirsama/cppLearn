#include <bits/stdc++.h>
using pip = std::pair<int, std::pair<int, int> >;

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::priority_queue<pip> pq;
    std::vector g(n, std::vector<int>(m));
    std::vector<bool> h(n), l(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> g[i][j];
            pq.push(pip(g[i][j], std::pair<int, int>(i, j)));
        }
    }
    while (k--) {
        auto [x,y] = pq.top();
        while (h[y.first] || l[y.second]) {
            pq.pop();
            x = pq.top().first;
            y = pq.top().second;
        }
        pq.pop();
        h[y.first] = true;
        l[y.second] = true;
    }
    for (int i = 0; i < n; i++) {
        if (h[i]) continue;
        bool have = false;
        for (int j = 0; j < m; j++) {
            if (l[j]) continue;
           if (have) std::cout << ' ';
            have = true;
            std::cout << g[i][j];
        }
        std::cout << '\n';
    }
}
