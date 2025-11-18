//  B3611 【模板】传递闭包
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
    i32 n;
    std::cin >> n;
    std::vector g(n, std::vector<i32>(n));
    for (auto &i: g) for (auto &j: i) std::cin >> j;
    for (auto &i: g) for (auto &j: i) j = !j;
    for (i32 k = 0; k < n; k++) {
        for (i32 i = 0; i < n; i++) {
            for (i32 j = 0; j < n; j++) {
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (auto &i: g) {
        for (auto &j: i) {
            std::cout << !j << ' ';
        }
        std::cout << endl;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}