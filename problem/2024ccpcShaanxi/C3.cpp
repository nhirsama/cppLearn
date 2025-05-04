#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> id(n * 2 + 1), od(n * 2 + 1);
    std::vector g(n * 2 + 1, std::vector<int>());
    for (int i = 1; i <= n; i++) {
        int t;
        std::cin >> t;
        g[i].push_back(t);
        id[t]++;
        od[i]++;
    }
    std::vector<int> len(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        if (id[i] == 0 && od[i]) {
            std::queue<int> u;
            u.push(i);
            len[i]++;
            while (!u.empty()) {
                auto v = u.front();
                u.pop();
                //std::cout<<v<<std::endl;

                if (n < v && v <= n * 2) {
                    continue;
                }
                //len[v]++;
                //len++;
                for (auto j: g[v]) {
                    id[j]--;
                    if (id[j] == 0) {
                        u.push(j);
                    }
                    //len[j] = std::max(len[j], len[v] + 1);
                    if (n < j && j <= n * 2) {
                        len[j] = std::max(len[j], len[v]);
                    } else {
                        len[j] = std::max(len[j], len[v] + 1);
                    }
                    od[v]--;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (id[i] == od[i] && od[i]) ans++;
    }
    for (int i = n + 1; i <= n * 2; i++) {
        ans += len[i];
    }
    std::cout << ans << std::endl;
}
