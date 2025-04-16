//  E. Boneca Ambalabu
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
    std::vector<i32> arr(n);
    for (auto &i: arr) std::cin >> i;
    std::vector<i32> zo(30);
    for (auto i: arr) {
        for (i32 j = 29; ~j; j--) {
            zo[29 - j] += ((i >> j) & 1);
        }
    }
    i64 ans = 0;
    for (auto i: arr) {
        i64 res = 0;
        for (i32 j = 0; j < 30; j++) {
            if ((i >> j) & 1) {
                res += (n - zo[29 - j]) * (1ll << j);
            } else {
                res += zo[29 - j] * (1ll << j);
            }
        }
        ans = std::max(ans, res);
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
