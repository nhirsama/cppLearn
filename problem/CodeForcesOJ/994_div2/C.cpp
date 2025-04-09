//C
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i64 n, x, y;
    std::cin >> n >> x >> y;
    // for (i32 i = 0; i < n; i++) {
    //     std::cout << ((i & 1) == (x&1)) << ' ';
    // }
    --x;
    --y;
    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[(x + i) % n] = (i & 1);
    if (n & 1 || (x - y & 1) == 0) ans[x] = 2;
    for (auto x: ans) std::cout << x << ' ';
    std::cout << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
