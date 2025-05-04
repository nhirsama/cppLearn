//  C. Competitive Fishing
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
    std::string s;
    std::cin >> s;
    std::vector<i32> cnt(n);
    i32 cnt1 = 0, cnt0 = 0;
    for (i32 i = n; i; i--) {
        if (s[i - 1] == '0') cnt0++;
        else cnt1++;
        cnt[i - 1] = cnt1 - cnt0;
    }
    cnt[0] = 0;
    std::ranges::sort(cnt, std::greater<>());
    i32 sum = 0;
    for (i32 i = 0; i < n; i++) {
        if (sum >= k) {
            std::cout << i + 1 << endl;
            return;
        }
        sum += cnt[i];
    }
    std::cout << -1 << endl;
    // i32 l = 0, r = n + 1;
    // auto check = [&](i32 mid) {
    //     i32 a = 0, b = 0;
    //     i32 cnt = 0;
    //     bool f = false;
    //     for (auto i: s) {
    //         if (cnt == mid - 1) {
    //             if (i == '1') b += cnt;
    //             else a += cnt;
    //         } else {
    //             if (i == '1') {
    //                 if (f) {
    //                     cnt++;
    //                     b += cnt;
    //                     //f = false;
    //                 } else {
    //                     f = true;
    //                     b += cnt;
    //                 }
    //             } else {
    //                 if (f) {
    //                     cnt++;
    //                     a += cnt;
    //                 } else {
    //                     a += cnt;
    //                     f = true;
    //                 }
    //             }
    //         }
    //     }
    //     i32 ra = 0,rb = 0;
    //     i32 rcnt = mid-1;
    //     bool rf = false;
    //     for (i32 i = n-1;~i && rcnt;i--) {
    //         auto c = s[i];
    //         if (c == '1') {
    //             rb+=rcnt;
    //             rf = true;
    //         }
    //         else {
    //             if (rf) {
    //                 rcnt--;
    //                 ra+=rcnt;
    //             }
    //             else {
    //                 ra+=rcnt;
    //                 rf = true;
    //             }
    //         }
    //     }
    //     return a + k <= b;
    // };
    // while (l < r) {
    //     i32 mid = l + r >> 1;
    //     if (check(mid)) r = mid;
    //     else l = mid + 1;
    // }
    // if (l == n + 1) {
    //     std::cout << -1 << endl;
    //     return;
    // } else std::cout << l << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
