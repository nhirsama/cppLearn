//  D. Come a Little Closer
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
using pii = std::pair<i32, i32>;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<pii> point(n);
    std::multiset<i32> xm, ym;
    for (auto &[x,y]: point) {
        std::cin >> x >> y;
        xm.insert(x);
        ym.insert(y);
    }
    i64 ans = 0x3f3f3f3f3f3f3f3f;

    for (auto [x,y]: point) {
        xm.erase(xm.find(x));
        ym.erase(ym.find(y));
        if (!xm.empty()) {
            i64 s = (*xm.rbegin() - *xm.begin() + 1) * (*ym.rbegin() - *ym.begin() + 1);
            if (s > n - 1) {
                ans = std::min(ans, s);
            } else {
                i32 xl = (*xm.rbegin() - *xm.begin() + 1);
                i32 yl = (*ym.rbegin() - *ym.begin() + 1);
                s = std::min(xl * yl + xl, xl * yl + yl);
                ans = std::min(ans, s);
            }
        } else {
            ans = std::min(ans, 1ll);
        }
        xm.insert(x);
        ym.insert(y);
    }

    std::cout << ans << endl;
    // std::vector<std::array<i32, 2> > x(n);
    // std::vector<std::array<i32, 2> > y(n);
    // // std::vector<i32> y(n);
    // for (i32 i = 0; i < n; i++) {
    //     std::cin >> x[i][0] >> y[i][0];
    //     y[i][1] = x[i][1] = i;
    // }
    // std::ranges::sort(x);
    // std::ranges::sort(y);
    //
    // auto check = [&](i32 xx, i32 yy) {
    //     i32 cnt = xx * yy;
    //     if (cnt < n) {
    //         cnt = xx * yy + yy;
    //         cnt = std::min(cnt, xx * yy + xx);
    //         return cnt;
    //     } else return cnt;
    // };
    // i32 ans = check(x.back()[0] - x[0][0] + 1, y.back()[0] - y[0][0] + 1);
    // if (n > 1) {
    //     ans = std::min(ans, check(x[n - 1][0] - x[1][0] + 1, y[n - 1][0] - y[0][0] + 1));
    //     ans = std::min(ans, check(x[n - 2][0] - x[0][0] + 1, y[n - 1][0] - y[0][0] + 1));
    //     ans = std::min(ans, check(x[n - 1][0] - x[0][0] + 1, y[n - 1][0] - y[1][0] + 1));
    //     ans = std::min(ans, check(x[n - 1][0] - x[0][0] + 1, y[n - 2][0] - y[0][0] + 1));
    //     if (x[n - 1][1] == y[n - 1][1]) {
    //         ans = std::min(ans, check(x[n - 2][0] - x[0][0] + 1, y[n - 2][0] - y[0][0] + 1));
    //     }
    //     if (x[0][1] == y[0][1]) {
    //         ans = std::min(ans, check(x[n - 1][0] - x[1][0] + 1, y[n - 1][0] - y[1][0] + 1));
    //     }
    //     // ans = std::min(ans, ((x.back() - x[1] + 1) * (y.back() - y[0] + 1) >= n)
    //     //                         ? ans
    //     //                         : (x.back() - x[1] + 1) * (y.back() - x[0] + 1));
    //     // ans = std::min(ans, ((x[n - 2] - x[0] + 1) * (y.back() - y[0] + 1) >= n)
    //     //                         ? ans
    //     //                         : (x[n - 2] - x[0] + 1) * (y.back() - x[0] + 1));
    //     // ans = std::min(ans, ((x.back() - x[0] + 1) * (y[n - 2] - y[0] + 1) >= n)
    //     //                         ? ans
    //     //                         : (x.back() - x[0] + 1) * (y[n - 2] - x[0] + 1));
    // }
    // std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
