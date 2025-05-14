//
// Created by ling on 25-5-14.
//
#include <bits/stdc++.h>
using f64 = double;
using i64 = long long;
using i32 = i64;
using f32 = long double;
using pii = std::pair<i32, i32>;
constexpr i32 inf = 0x3f3f3f3f3f3f;

f32 getdist(pii a, pii b) {
    return std::sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
    i32 n, m, k;
    std::cin >> n >> m >> k;
    i32 b, e;
    std::cin >> b >> e;
    std::vector<pii> ct(4);
    for (auto &[x,y]: ct) std::cin >> x >> y;
    std::vector<pii> stu(k);
    for (auto &[x,y]: stu) std::cin >> x >> y;
    std::vector<std::array<f32, 4> > w(k, {0, inf, inf, inf});
    std::vector<bool> st(4);
    auto dfs = [&](auto &&self, i32 i, i32 cnt, f32 dist, i32 fa)-> void {
        w[i][cnt] = std::min(w[i][cnt], dist + getdist(fa == -1 ? stu[i] : ct[fa], ct[3]));
        for (i32 j = 0; j < 3; j++) {
            if (st[j]) continue;
            st[j] = true;
            self(self, i, cnt + 1, dist + getdist(fa == -1 ? stu[i] : ct[fa], ct[j]), j);
            st[j] = false;
        }
    };
    for (i32 i = 0; i < k; i++) {
        dfs(dfs, i, 0, 0.0, -1);
    }
    std::vector<f32> dp(1005, inf);
    dp[0] = 0;
    for (i32 i = 0; i < k; i++) {
        for (i32 j = 1003; ~j; j--) {
            for (i32 a = 0; a <= 3; a++) {
                if (j < a)break;
                dp[j] = std::min(dp[j], dp[j - a] + w[i][a]);
            }
        }
    }
    i32 dd = std::max(n / b + (n % b != 0), m / e + (m % e != 0));
    f32 ans = inf;
    for (i32 i = dd; i <= 1003; i++) {
        ans = std::min(dp[i], ans);
    }
    printf("%.10Lf\n", ans);
}
