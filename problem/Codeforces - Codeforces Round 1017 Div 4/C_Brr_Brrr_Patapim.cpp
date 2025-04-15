//  C. Brr Brrr Patapim
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
    std::vector<i32> ans(2 * n);
    i64 sum = n + 2 * n * n;
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < n; j++) {
            ans[i + j + 1] = g[i][j];
        }
    }

    ans[0] = sum - std::accumulate(all(ans), 0);
    for (auto i: ans) std::cout << i << ' ';
    std::cout << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
