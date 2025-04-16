//模板
#include <bits/stdc++.h>
using i64 = long long int;
using i32 = int;
using u64 = unsigned long long;
using pii = std::pair<i64, i64>;
constexpr int N = 1e5 + 10;
constexpr int mod = 998244353;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i64 n;
    std::cin >> n;
    std::vector<i64> d(n);
    for (auto &i: d) std::cin >> i;
    i64 dxn = 0, now = 0;
    i64 m;
    std::cin >> m;
    while (m--) {
        i32 op;
        std::cin >> op;
        if (op == 0) {
            now++;
            dxn = std::max(dxn, now);
        } else {
            now--;
        }
    }
    for (i32 i = 0; i < n; i++) {
        if (i < dxn) {
            std::cout << 0 << " \n"[i == n-1];
        } else {
            std::cout << d[i] << " \n"[i == n-1];
        }
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
