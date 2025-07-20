//  76构造
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    auto lowbit = [](i32 x) {
        return x & -x;
    };
    auto highbit = [&](i32 x) {
        while (x != lowbit(x)) {
            x -= lowbit(x);
        }
        return x;
    };
    i32 n, m;
    std::cin >> n >> m;
    if (m & 1) {
        if (highbit(n) < highbit(m)) {
            std::cout << -1 << enld;
        } else {
            std::vector<bool> vis(std::max(n, m) + 1);
            std::vector<std::array<i32, 2>> sli;
            i32 it = 1;
            m -= lowbit(m);
            while (m) {
                std::cout << lowbit(m) << ' ';
                sli.push_back({it, it++});
                vis[lowbit(m)] = true;
                m -= lowbit(m);
            }
            for (i32 i = 1; i <= n; i++) {
                if (!vis[i]) {
                    std::cout << i << ' ';
                }
            }
            std::cout << endl;
            sli.push_back({it, n});
            std::cout << sli.size() << endl;
            for (auto [x, y]: sli) {
                std::cout << x << ' ' << y << enld;
            }
        }
    } else {
        std::cout << -1 << endl;
        return;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}