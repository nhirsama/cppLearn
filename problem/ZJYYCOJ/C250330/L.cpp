//模板
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
    i64 n, x;
    std::cin >> n >> x;
    std::vector<i64> v(n);
    for (auto &i: v) {
        std::cin >> i;
    }
    std::sort(all(v));
    for (i32 i = 0; i < n; i++) {
        i64 p = lower_bound(all(v), x + v[i]) - v.begin();
        if (p == n) continue;
        if ((v[i] - v[p] == x) || (v[i] - v[p] == -x)) {
            std::cout << "Yes" << endl;
            return;
        }
    }
    std::cout << "No" << endl;
}

signed main() {
    IOS;
    i32 T = 1;

    while (T--) nhir();
    return 0;
}
