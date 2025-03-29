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
    i64 ans = 365 - 31 - 28 - 29;
    for (i32 i = 2026; i < 46 * 46; i++) {
        ans += 365;
        if (i % 4 == 0) ans++;
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
