//C
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i64 ans, n, k;
    std::cin >> n >> k;
    // auto bfs = [&](auto &&self, i64 l, i64 r)-> i64 {
    //     if (r - l + 1 < k) {
    //         return 0;
    //     } else {
    //         i64 m = (l + r) >> 1;
    //         if ((r - l + 1) & 1) {
    //             return m + self(self, l, m - 1) + self(self, m + 1, r);
    //         } else {
    //             return self(self, l, m) + self(self, m + 1, r);
    //         }
    //     }
    // };
    // ans = bfs(bfs, 1, n);
    i64 cur = 1, cnt = 0, t = n + 1;
    while (n >= k) {
        if (n & 1) cnt += cur;
        cur <<= 1;
        n >>= 1;
    }
    std::cout << t * cnt / 2 << endl;
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
