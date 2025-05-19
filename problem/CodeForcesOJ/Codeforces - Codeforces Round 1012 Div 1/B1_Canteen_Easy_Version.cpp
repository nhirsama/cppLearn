//  B1. Canteen (Easy Version)
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> a(n * 2), b(n * 2);
    for (i32 i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }
    for (i32 i = 0; i < n; i++) {
        std::cin >> b[i];
        a[i] = a[i + n] = a[i] - b[i];
    }
    for (i32 i = 1; i < 2 * n; i++) {
        a[i] += a[i - 1];
    }
    std::stack<i32> s;
    i32 ans = 0;
    for (i32 i = 2 * n - 1; ~i; i--) {
        while (!s.empty() && a[s.top()] > a[i]) s.pop();
        if (i < n) ans = std::max(ans, s.top() - i);
        s.push(i);
    }
    // for (auto &i: a) std::cin >> i;
    // for (auto &i: b) std::cin >> i;
    // i32 cnt = 0, ans = 0;
    // while (true) {
    //     ans++;
    //     bool flag = true;
    //     for (i32 i = 0; i < n; i++) {
    //         i32 min = std::min(b[(i + cnt) % n], a[i]);
    //         b[(i + cnt) % n] -= min;
    //         a[i] -= min;
    //         if (a[i]) flag = false;
    //     }
    //     //for (auto i: a)std::cout << i << ' ';
    //     //std::cout << endl;
    //     if (flag) break;
    //     cnt++;
    // }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
