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

void nhir() {
    std::string s;
    std::cin >> s;
    i64 ans = 1;
    for (char i: s) {
        i32 t = i - '0';
        i32 cnt = 0;
        for (i32 j = 0; j <= t; j++) {
            for (i32 k = 0; k <= t - j; k++) {
                for (i32 n = 0; n <= t - j - k; n++) {
                    if (j + k + n == t)cnt++;
                }
            }
        }
        ans *= cnt;
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
