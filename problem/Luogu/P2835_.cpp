//  P2835 刻录光盘
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
    int n;
    std::cin >> n;
    std::vector g(n + 1, std::vector<int>());
    for (int i = 1; i <= n; i++) {
        int v;
        while(std::cin>>v){
            if(v == 0) break;
            g[i].push_back(v);
        }
    }
    std::vector<int> low(n + 1), dfn(n + 1);
    std::vector<bool> st(n + 1);
    std::stack<int> s;
    std::vector<int> col(n + 1), size(n + 1);
    int colcnt = 0, dfnc = 0;
    auto tarjan = [&](auto &&self, int u)-> void {
        low[u] = dfn[u] = ++dfnc;
        s.push(u);
        st[u] = true;
        for (auto i: g[u]) {
            if (!dfn[i]) {
                self(self, i);
                low[u] = std::min(low[u], low[i]);
            } else if (st[i]) low[u] = std::min(low[u], low[i]);
        }
        if (low[u] == dfn[u]) {
            st[u] = false;
            col[u] = ++colcnt;
            size[colcnt] = 1;
            while (s.top() != u) {
                col[s.top()] = colcnt;
                st[s.top()] = false;
                size[colcnt]++;
                s.pop();
            }
            s.pop();
        }
    };

    for (int i = 1; i <= n; i++) {
        if (col[i]) continue;
        tarjan(tarjan, i);
    }
    std::vector<int> rd(colcnt + 1);
    for (int i = 1; i <= n; i++) {
        for (auto j: g[i]) {
            if (col[i] == col[j]) continue;
            rd[col[j]]++;
        }
    }
    int ans = std::count(rd.begin() + 1, rd.end(), 0);
    std::cout << ans;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}