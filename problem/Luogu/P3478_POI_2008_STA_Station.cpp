//  P3478 [POI 2008] STA-Station
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector tr(n + 1, std::vector<i32>());
    for (i32 i = 1; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    std::vector<i32> ans(n + 1);
    std::vector<i32> cnt(n + 1);
    auto dfs = [&](auto &&self, i32 u, i32 f)-> void {
        for (auto v: tr[u]) {
            if (f == v) continue;
            self(self, v, u);
            //逆天，深度之和我看成深度的最大值，然后甚至有75分。
            //cnt[u] = std::max(cnt[u], cnt[v]+1);
            cnt[u] += cnt[v];
        }
        cnt[u]++;
    };
    dfs(dfs, 1, 1);
    auto dfs2 = [&](auto &&self, i32 u, i32 f)-> void {
        for (auto v: tr[u]) {
            if (v == f) continue;
            ans[v] = ans[u] - cnt[v] * 2 + n;
            self(self, v, u);
        }
        // cnt[f]+=tr[u].size()-1;
        // cnt[f] = fmax;
        // cnt[u] = 1;
        // for (auto v: tr[u]) {
        //     cnt[u] = std::max(cnt[u], cnt[v] + 1);
        // }
        // ans[u] = cnt[u];
        // for (auto v: tr[u]) {
        //     if (f == v) continue;
        //     self(self, v, u);
        // }
        // cnt[f] = ft;
        // cnt[u] = t;
    };
    dfs2(dfs2, 1, 1);
    std::cout << std::max_element(ans.begin() + 1, ans.end()) - ans.begin();
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
