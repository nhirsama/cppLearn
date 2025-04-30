#include <bits/stdc++.h>
using i32 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i32> a(n), b(n);
    for (auto &i: a) std::cin >> i;
    for (auto &i: b) std::cin >> i;
    i32 l = 0, r = 1e9;
    auto check = [&](i32 mid)-> bool {
        i32 up = 1e18, lo = -1e18;
        for (i32 i = 0; i < n; i++) {
            up = std::min(up, mid * b[i] + a[i]);
            lo = std::max(lo, a[i] - b[i] * mid);
            if (up < lo) return false;
        }
        return lo <= up;
    };
    while (l < r) {
        i32 mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else l = mid + 1;
    }
    std::cout << r << '\n';
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
/*
1
4
2 2 2 2
1 1 1 1
*/