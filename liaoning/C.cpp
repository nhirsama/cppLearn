#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    vector<i64> num(n + 1);
    vector tree(n + 1, vector<i64>());
    for (int i = 1; i <= n; i++) {
        int u;
        std::cin >> u >> num[i];

        tree[u].push_back(i);
    }
    vector<i64> cnt(n + 1);
    vector<i64> xz, xzz;
    num[0] = 2200;
    auto dfs = [&](auto &&self, int u)-> void {
        for (auto i: tree[u]) {
            self(self, i);
            cnt[u] += cnt[i];
        }
        if (tree[u].size() == 0) cnt[u] = num[u];
        else {
            if (num[u] > 2200) num[u] = 2200;
            xz.push_back(cnt[u]);
            xzz.push_back(num[u]);
        }
    };
    dfs(dfs, 0);
    sort(xz.begin(), xz.end());
    sort(xzz.begin(), xzz.end());
    for (int i = 0; i < xz.size(); i++) {
        if (xz[i] > xzz[i]) {
            std::cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
