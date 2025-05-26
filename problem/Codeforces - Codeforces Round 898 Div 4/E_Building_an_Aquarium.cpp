//  E. Building an Aquarium
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n, x;
    std::cin >> n >> x;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    std::ranges::sort(v);
    std::vector<i32> pre(n + 1);
    for (i32 i = 0; i < n; i++) {
//        pre[i] = (i ? pre[i - 1] : 0) + v[i];
        pre[i + 1] = pre[i] + v[i];
    }
    i32 l = 0, r = 5e13;
    auto check = [&](i32 mid) -> bool {
        i32 p = std::ranges::upper_bound(v, mid) - v.begin();
        return mid * p - pre[p] <= x;
    };
    while (l < r) {
        i32 mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    std::cout << r << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}