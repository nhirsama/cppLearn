//  C. Beavermuncher-0xFF
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
    std::vector tr(n, std::vector<i32>());
    std::vector<i32> w(n);
    for (auto &i: w) std::cin >> i;
    for (i32 i = 1; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        u--, v--;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    w[0]++;
    i32 ans = 0;
    auto dfs = [&](auto &&self, i32 u, i32 f)-> void {
        if (--w[u] == 0) return;
        ans++;
        for (auto v: tr[u]) {
            if (v == f)continue;
            if (w[v] == 0) continue;
            self(self, v, u);
        }
        i32 ea = 0;
        if (f != -1) {
            if (w[f] - 1 > w[u]) ea = w[f] * 2 - 1;
            else ea = w[u] * 2;
            w[f] -= ea;
            w[u] -= ea;
            ans += ea;
        }
    };
    dfs(dfs, 0, -1);
    std::cout << --ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
