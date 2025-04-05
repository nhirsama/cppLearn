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
    i32 n;
    std::cin >> n;
    std::vector<i64> v(n);
    for (i64 &i: v) std::cin >> i;
    std::sort(all(v));
    if (v[0] == v[1]) {
        std::cout << "YES\n";
        return;
    }
    std::set<i64> s;
    for (i32 i = 1; i < n; i++) {
        if (v[i] % v[0] == 0) {
            s.insert(v[i] / v[0]);
        }
    }
    i64 gcd = -1;
    for (auto i: s) {
        if (gcd == -1) gcd = i;
        else {
            gcd = std::gcd(gcd, i);
        }
    }
    if (gcd == 1) {
        std::cout << "YES\n";
    } else std::cout << "NO\n";
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
