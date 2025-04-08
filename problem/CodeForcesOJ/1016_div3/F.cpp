//F
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
    i32 n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    std::vector b(m, std::vector<std::string>(n));
    for (auto &i: a) {
        std::cin >> i;
    }
    for (auto &i: b) {
        for (auto &j: i) {
            std::cin >> j;
        }
    }
    for (i32 j = 0; j < n; j++) {
        bool flag = false;
        for (i32 i = 0; i < m; i++) {
            if (b[i][j] == a[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            std::cout << -1 << endl;
            return;
        }
    }
    i32 aa = 0;
    for (i32 i = 0; i < m; i++) {
        i32 cnt = 0;
        for (i32 j = 0; j < n; j++) {
            if (b[i][j] == a[j])
                cnt++;
        }
        aa = std::max(aa, cnt);
    }
    i32 ans = 0;
    if (n <= aa) {
        ans = n;
    } else {
        ans = 3 * n - 2 * aa;
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
