//F
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 2e5 + 10;
constexpr i32 mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
std::vector<i64> jc(N);

i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

i64 C(i64 n, i64 k) {
    if (n < k) return 0ll;
    return (jc[n] * power((jc[n - k] * jc[k]) % mod, mod - 2, mod)) % mod;
}

void nhir() {
    i64 n, k;
    std::cin >> n >> k;
    i64 x = 0,y = 0;
    for (i32 _ = 0; _ < n; _++) {
        i32 c;
        std::cin >> c;
        if (c)
            y++;
        else
            x++;
    }
    i64 ans = 0;
    for (i64 i = k / 2 + 1; i <= std::min(y, k); i++) {
        ans = (ans + C(y, i) * C(n - y, k - i) % mod + mod) % mod;
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    jc[0] = 1;
    for (i32 i = 1; i < N; i++) jc[i] = jc[i - 1] * i % mod;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
