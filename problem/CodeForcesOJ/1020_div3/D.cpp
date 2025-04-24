//D
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9+7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (auto &i : a) std::cin >> i;
    for (auto &i : b) std::cin >> i;

    std::vector<int> f(m+1), g(m+1);
    f[0] = -1;
    for (int i = 0; i < m; i++) {
        int p = f[i] + 1;
        while (p < n && a[p] < b[i]) ++p;
        f[i+1] = p;
    }
    if (f[m] < n) {
        std::cout << 0 << endl;
        return;
    }
    g[m] = n;
    for (int i = m-1; i >= 0; i--) {
        int p = g[i+1] - 1;
        while (p >= 0 && a[p] < b[i]) --p;
        g[i] = p;
    }
    int ans = 0x3f3f3f3f;
    for (int j = 0; j < m; j++) {
        if (f[j] < g[j+1])
            ans = std::min(ans, b[j]);
    }
    std::cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin>>T;
    while (T--) nhir();
    return 0;
}
