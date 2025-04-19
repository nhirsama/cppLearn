//  F. Minimum Maximum Distance
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i32 n, k;
    std::cin >> n >> k;

    std::vector g(n, std::vector<int>());
    std::vector<bool> flag(n);
    int beg = 0;
    for (int i = 1; i <= k; i++) {
        int a;
        std::cin >> a;

        a--;
        beg = a;
        flag[a] = true;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (k == 1) {
        std::cout << 0 << endl;
        return ;
    }
    std::queue<pii> q;
    std::vector<bool> vi(n);
    q.push({beg, 0});
    int maxp = 0, maxd = 0;
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if (vi[x]) continue;
        vi[x] = true;
        for (auto i: g[x]) {
            if (vi[i]) continue;
            if (flag[i] && y + 1 > maxd) {
                maxd = y + 1;
                maxp = i;
            }
            q.push({i, y + 1});
        }
    }
    vi = std::vector<bool>(n);
    q.push({maxp, 0});
    maxp = 0, maxd = 0;
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if (vi[x]) continue;
        vi[x] = true;
        for (auto i: g[x]) {
            if (vi[i]) continue;
            if (flag[i] && y + 1 > maxd) {
                maxd = y + 1;
                maxp = i;
            }
            q.push({i, y + 1});
        }
    }
    std::cout << (maxd + 1) / 2 << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
