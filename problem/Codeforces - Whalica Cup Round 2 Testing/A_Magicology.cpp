//  A. Magicology
//  16:58
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 998244353;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector t(n, std::vector<i32>());
    auto a = v;
    auto aa = v;
    for (i32 i = 1; i < n; i++) {
        i32 u, vv;
        std::cin >> u >> vv;
        u--, vv--;
        t[u].push_back(vv);
        t[vv].push_back(u);
    }
    auto dfs = [&](this auto &&self, i32 f, i32 u)-> void {
        for (auto vv: t[u]) {
            if (vv == f) continue;
            self(u, vv);
            v[u] = (v[u] + (k - 1) * v[vv] % mod) % mod;
        }
    };
    dfs(0, 0);

    auto dfs2 = [&](this auto &&self, i32 f, i32 u)-> void {
        for (auto vv: t[u]) {
            if (vv == f) continue;
            self(u, vv);

            if (a[vv] != aa[vv]) a[u] = (a[u] + v[vv] % mod) % mod;
            a[u] = (a[u] + k * a[vv] % mod) % mod;
        }
    };
    dfs2(0, 0);
    for (auto i: a) {
        std::cout << i << ' ';
    }
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}