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
    std::vector<std::string> v(n);
    std::vector<std::vector<i32> > g(n + 1);
    for (auto &i: v) std::cin >> i;
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < n; j++) {
            if (v[i][j] == '1') g[i + 1].push_back(j + 1);
        }
    }
    std::vector<bool> st(n + 1);
    auto dfs = [&](auto &&self, i32 u)-> void {
        st[u] = true;
        std::sort(all(g[u]), [](i32 a, i32 b) { return a > b; });
        for (auto v: g[u]) {
            if (st[v]) continue;
            if (v > u) continue;
            self(self, v);
        }
        std::cout << u << ' ';
    };
    for (i32 i = n; i; i--) {
        if (st[i]) continue;
        dfs(dfs, i);
    }
    std::cout << endl;
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
