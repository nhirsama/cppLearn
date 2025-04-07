//模板
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
    i64 n;
    i64 max = 0x3f3f3f3f3f3f3f;
    i64 min = 0;
    std::cin >> n;
    for (i32 i = 1; i <= n; i++) {
        i64 a, b;
        std::cin >> a >> b;
        max = std::min(max, a / b);
        min = std::max(min, a / (b + 1) + 1);
    }
    std::cout << min << ' ' << max << endl;
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
