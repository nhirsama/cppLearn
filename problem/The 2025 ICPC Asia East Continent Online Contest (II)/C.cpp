#include  <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n;
    std::cin >> n;
    std::vector<i64> v(9);
    for (int i = 1; i < 8; i++) {
        std::cin >> v[i];
    }
    i64 l = 0, r = n;
    auto check = [&](i64 mid) {
        std::vector<std::vector<int> > tt = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {2, 0, 1}, {1, 2, 0}, {2, 1, 0}};
        const std::vector<std::vector<int> > ii = {
            {1, 2, 4, 3, 5, 6, 7},
            {1, 2, 4, 5, 3, 6, 7},
            {1, 2, 4, 3, 6, 5, 7},
            {1, 2, 4, 5, 6, 3, 7},
            {1, 2, 4, 6, 3, 5, 7},
            {1, 2, 4, 6, 5, 3, 7},
        };
        for (int m = 0; m < 6; m++) {
            std::vector<i64> cnt(3);
            for (auto i: ii[m]) {
                int t = v[i];
                for (auto j: tt[m]) {
                    if ((i & (1 << j)) && cnt[j] < mid) {
                        if (cnt[j] + t <= mid) {
                            cnt[j] += t;
                            t = 0;
                        } else {
                            t -= mid - cnt[j];
                            cnt[j] = mid;
                        }
                    }
                }
            }
            if (cnt[0] >= mid && cnt[1] >= mid && cnt[2] >= mid) return true;
        }
        // for (auto k: tt) {
        //     // i64 cnt[3]{};
        //     for (auto iii: ii) {
        //         std::vector<i64> cnt(3);
        //         for (auto i: iii) {
        //             i64 t = v[i];
        //             for (int jj = 0; jj < 3; jj++) {
        //                 int j = k[jj];
        //                 if ((i & (1 << j)) && cnt[j] < mid) {
        //                     if (cnt[j] + t <= mid) {
        //                         cnt[j] += t;
        //                         t = 0;
        //                     } else {
        //                         t -= mid - cnt[j];
        //                         cnt[j] = mid;
        //                     }
        //                 }
        //             }
        //         }
        //         if (cnt[0] >= mid && cnt[1] >= mid && cnt[2] >= mid) return true;
        //     }
        // }
        return false;
    };
    while (l + 1 < r) {
        // i64 mid = (l + r + 1) / 2;
        // if (check(mid)) l = mid;
        // else r = mid - 1;
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    std::cout << l << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}

/*
 1
 0
 0 0 0 0 0 0 0

1
30
100000 100000 0 0 0 0 1
 */
