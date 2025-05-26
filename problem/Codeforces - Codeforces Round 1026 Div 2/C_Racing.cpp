//  C. Racing
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
using pii = std::pair<i32, i32>;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector<pii> high(n);
    for (auto &[l,r]: high) std::cin >> l >> r;
    std::vector<i32> l(n), r(n);
    i32 ll = 0, rr = 0;
    for (i32 i = 0; i < n; i++) {
        i32 low = ll + (v[i] == 1);
        i32 up = rr + (v[i] != 0);
        if (v[i] == 0) up = rr;
        auto [li, ri] = high[i];
        l[i] = std::max(low, li);
        r[i] = std::min(up, ri);
        if (l[i] > r[i]) {
            std::cout << -1 << '\n';
            return;
        }
        ll = l[i];
        rr = r[i];
    }
    std::vector<i32> h(n), ans(n);
    h[n - 1] = l[n - 1];
    for (i32 i = n - 1; ~i; i--) {
        if (v[i] == 0 || (v[i] == -1 && (i > 0 ? l[i - 1] : 0) <= h[i] && h[i] <= (i > 0 ? r[i - 1] : 0))) {
            ans[i] = 0;
            if (i > 0) h[i - 1] = h[i];
        } else {
            ans[i] = 1;
            if (i > 0) h[i - 1] = h[i] - 1;
        }
    }

    for (i32 i: ans) std::cout << i << ' ';
    std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
