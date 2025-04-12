//P8780 [蓝桥杯 2022 省 B] 刷题统计
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
    i64 a, b, n;
    std::cin >> a >> b >> n;
    i64 ans = 0;
    ans += n / (a * 5 + b * 2) * 7;
    n %= (a * 5 + b * 2);
    if (n <= a * 5) {
        ans += n / a + (n % a != 0);
    } else {
        ans += 5;
        n -= 5 * a;
        ans += n / b + (n % b != 0);
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }

    while (T--) nhir();
    return 0;
}
