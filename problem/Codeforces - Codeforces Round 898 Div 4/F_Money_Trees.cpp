//  F. Money Trees
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> a(n), h(n);
//    for (i32 i = 1; i <= n; i++) std::cin >> b[i];
//    for (i32 i = 1; i <= n; i++) std::cin >> v[i];
    std::vector<i32> pre(n + 1);
    for (auto &i: a) std::cin >> i;
    for (auto &i: h) std::cin >> i;
    for (i32 i = 0; i < n; i++) {
        pre[i + 1] = a[i] + pre[i];
    }
    std::vector<i32> len(n + 1);
    len[0] = 1;
    for (i32 i = 0; i < n - 1; i++) {
        if (h[i] % h[i + 1] == 0) {
            len[i + 1] = len[i] + 1;
        } else len[i + 1] = 1;
    }
//    for (auto i: len) {
//        std::cout << i << ' ';
//    }
//    std::cout << endl;
//    for (auto i: pre) {
//        std::cout << i << ' ';
//    }
    auto check = [&](i32 mid) {
        for (i32 i = 0; i + mid < n; i++) {
            if (len[i + mid - 1] < mid - 1) continue;
            if (pre[i + mid] - pre[i] <= k) return true;
        }
        return false;
    };
    i32 l = 0, r = n;
    while (l < r) {
        i32 mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    std::cout << l << endl;
    //    v[0] = 1;
//    i32 pl = 1, pr = 1, kk = 0;
//    i32 ans = 0;
//    while (pl <= pr && pr <= n) {
//        while (pr <= n && v[pr] % v[pr+1] == 0 && kk + b[pr] <= k) kk += b[pr++];
//        ans = std::max(ans, pr - pl);
//        k -= b[pl++];
//    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}