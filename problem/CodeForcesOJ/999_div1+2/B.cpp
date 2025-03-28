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
    std::vector<i32> v(n);
    std::map<i32, i32> m;
    i32 ans1[2]{0}, ans2 = 0;
    for (auto &_: v) {
        std::cin >> _;
        m[_]++;
        if (m[_] == 2) {
            ans1[1] = ans1[0];
            ans1[0] = _;
        }
        if (m[_] == 4) {
            ans2 = _;
        }
    }
    if (ans2) {
        for (i32 _ = 0; _ < 4; _++) {
            std::cout << ans2 << ' ';
        }
        std::cout << endl;
        return;
    } else if (ans1[0] && ans1[1]) {
        std::cout << ans1[0] << ' ' << ans1[0] << ' ' << ans1[1] << ' ' << ans1[1] << endl;
        return;
    } else if (ans1[0] == 0 && ans1[1] == 0) {
        std::cout << -1 << endl;
        return;
    }
    sort(all(v));
    auto p = std::lower_bound(all(v), ans1[0]);
    v.erase(p, p + 2);
    for (i32 i = 0; i < n - 3; i++) {
        if (v[i + 1] - v[i] < 2 * ans1[0]) {
            std::cout << ans1[0] << ' ' << ans1[0] << ' ' << v[i + 1] << ' ' << v[i] << endl;
            return;
        }
    }

    std::cout << -1 << endl;
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
