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

void nhir() {
    i64 n;
    std::cin >> n;
    std::vector<i64> a(n + 1), c(n + 1), root(n + 1);
    auto find = [&](auto &self, i32 u)-> i32 {
        return root[u] == u ? u : root[u] = self(self, root[u]);
    };
    for (i32 i = 1; i <= n; i++) std::cin >> a[i], root[i] = i;
    for (i32 i = 1; i <= n; i++) root[find(find, a[i])] = find(find, a[a[i]]);
    for (i32 i = 1; i <= n; i++) c[find(find, i)]++;
    i64 ans = 0;
    for (i32 i = 1; i <= n; i++) {
        i64 t = 0;
        std::cin >> t;
        ans += c[find(find, t)];
        std::cout << ans << ' ';
        c[find(find, t)] = 0;
    }
    std::cout << '\n';
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
