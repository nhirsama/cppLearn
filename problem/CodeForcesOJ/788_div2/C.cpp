//C
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

int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

void nhir() {
    i64 n;
    std::cin >> n;
    std::vector<i64> a(n + 1), b(n + 1), d(n + 1), root(n + 1);
    auto find = [&](auto &self, i32 u)-> i32 {
        return root[u] == u ? u : root[u] = self(self, root[u]);
    };
    for (i32 i = 1; i <= n; i++) std::cin >> a[i], root[i] = i;
    for (i32 i = 1; i <= n; i++) std::cin >> b[i];
    for (i32 i = 1; i <= n; i++) std::cin >> d[i];
    for (i32 i = 1; i <= n; i++) root[find(find, a[i])] = find(find, b[i]);
    for (i32 i = 1; i <= n; i++) {
        if (d[i]) root[find(find, d[i])] = 0;
    }
    i64 cnt = 0;
    for (i32 i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            root[find(find, a[i])] = 0;
        };
        if (find(find, a[i])) {
            cnt++;
            root[find(find, a[i])] = 0;
        }
    }
    i64 ans = 0;
    ans = power(2, cnt, mod);
    std::cout << ans << '\n';
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
