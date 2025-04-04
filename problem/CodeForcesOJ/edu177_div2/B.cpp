//B
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
    i64 n, k, x;
    std::cin >> n >> k >> x;
    std::vector<i64> v(n), pre(n + 1);
    for (auto &i: v) std::cin >> i;
    for (i32 i = n - 1; ~i; i--) pre[i] = pre[i + 1] + v[i];
    if (pre[0] * k < x) {
        std::cout << 0 << endl;
        return;
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (pre[i] >= x) {
            ans += k;
        } else {
            i64 t = x - pre[i];
            i64 cnt = k - (t + pre[0] - 1) / pre[0];
            if (cnt < 0) cnt = 0;
            ans += cnt;
        }
    }
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
