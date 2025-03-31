//E
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

i64 power(i64 a, i64 b, i64 p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

void nhir() {
    i64 n, m, k;
    std::cin >> n >> m >> k;
    i32 cnt = 0, edge = 0;
    for (i32 i = 0; i < k; i++) {
        i32 x,y, c;
        std::cin >> x >> y >> c;
        if ((x == 1 && y == 1) || (x == 1 && y == m) || (x == n && y == 1) || (x == n && y == m))continue;
        if ((x == 1 || y == 1 || x == n || y == m)) {
            edge += c;
            cnt++;
        }
    }
    if (cnt == (n + m - 4) * 2) {
        if (edge & 1) {
            std::cout << 0 << endl;
        } else std::cout << power(2, n * m - k, mod) << endl;
        return;
    }
    i64 ans = power(2, n * m - k - 1, mod);
    std::cout << ans << endl;
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
