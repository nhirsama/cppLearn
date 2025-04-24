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
    int n, x;
    std::cin >> n >> x;
    if (x == 0) {
        for (int i = 1; i < n; i++) {
            std::cout << i << ' ';
        }
        std::cout << 0 << endl;
    } else if (x == n) {
        for (int i = 0; i < n; i++) {
            std::cout << i << ' ';
        }
        std::cout << endl;
    } else {
        for (int i = 0; i < x; i++) {
            std::cout << i << ' ';
        }
        for (int i = x + 1; i < n; i++) {
            std::cout << i << ' ';
        }
        std::cout << x << endl;
    }
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
