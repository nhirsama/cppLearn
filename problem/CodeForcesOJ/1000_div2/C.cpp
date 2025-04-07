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
    i32 n;
    std::cin >> n;
    std::vector g(n + 1, std::vector<i32>());
    for (i32 i = 1; i < n; i++) {
        i32 u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<i32> cnt(n + 1);
    for (i32 i = 1; i <= n; i++) {
        cnt[i] = g[i].size();
    }
    std::multiset<i32> m;
    for (int i = 1; i <= n; i++) {
        m.insert(cnt[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (auto v: g[i]) {
            m.extract(cnt[v]);
        }
        m.extract(cnt[i]);
        if (!m.empty()) ans = std::max(ans, cnt[i] + *m.rbegin() - 1);
        for (auto v: g[i]) {
            m.insert(cnt[v]);
            ans = std::max(ans, cnt[i] + cnt[v] - 2);
        }
        m.insert(cnt[i]);
    }
    // i32 ans = 1;
    // i32 p = 0;
    // cnt[0] = -0x3f3f3f3f3f3f;
    // for (i32 i = 1; i <= n; i++) {
    //     if (cnt[i] > cnt[p]) p = i;
    // }
    // ans += cnt[p]-1;
    // cnt[p] = -0x3f3f3f3f3f3f;
    // for (auto v: g[p]) {
    //     cnt[v] --;
    // }
    // p = 0;
    // for (i32 i = 1; i <= n; i++) {
    //     if (cnt[i] > cnt[p]) p = i;
    // }
    // ans += cnt[p]-1;
    std::cout << ans << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        //freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
