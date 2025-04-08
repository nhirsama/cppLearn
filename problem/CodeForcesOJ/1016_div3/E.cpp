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
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> a(n);
    for (i32 i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    auto check = [&](i32 mid) {
        i32 kk = 0;
        i32 p = 0;
        std::vector<bool> st(mid);
        for (i32 num: a) {
            if (num < mid && !st[num]) {
                st[num] = true;
                p++;
            }
            if (p == mid) {
                kk++;
                st = std::vector<bool>(mid);
                p = 0;
            }
        }
        return kk >= k;
    };
    i32 l = 0, r = n + 1;
    while (l < r) {
        i32 mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    std::cout << l - 1 << endl;
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
