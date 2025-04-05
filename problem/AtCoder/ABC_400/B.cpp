//B
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
    i64 a, b;
    std::cin >> a >> b;
    if (b == 1) {
        if (a + 1 > 1e9) {
            std::cout << "inf" << endl;
        } else std::cout << a + 1;
    } else {
        i64 ans = 1;
        i64 pow = 1;
        for (i32 i = 1; i <= b; i++) {
            pow *= a;
            ans += pow;

            if (ans > 1e9) {
                std::cout << "inf";
                return;
            }
        }
        std::cout << ans;
    }
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
