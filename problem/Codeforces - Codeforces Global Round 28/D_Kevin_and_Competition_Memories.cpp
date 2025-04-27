//  D. Kevin and Competition Memories
#include <bits/stdc++.h>
using i32 = long long int;
using i64 = long long int;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i64 n, m;
    std::cin >> n >> m;
    std::vector<i64> v(1);
    for (i64 i = 0; i < n; i++) {
        if (i) {
            i64 t;
            std::cin >> t;
            if (t > v[0]) v.push_back(t);
        } else std::cin >> v[0];
    }
    std::vector<i64> p(m);
    for (auto &i: p) {
        std::cin >> i;
        if (i <= v[0]) i = inf;
    }
    std::ranges::sort(v);
    std::ranges::sort(p);
    std::vector<i64> ac;
    for (auto i: p) ac.push_back(v.end() - std::ranges::lower_bound(v, i));
    std::ranges::sort(ac);
    for (i64 k = 1; k <= m; k++) {
        i64 cnt = 0;
        for (i64 i = k - 1; i < m; i += k) cnt += ac[i] + 1;
        std::cout << cnt << ' ';
    }
    std::cout << endl;
}

signed main() {
    IOS;
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
