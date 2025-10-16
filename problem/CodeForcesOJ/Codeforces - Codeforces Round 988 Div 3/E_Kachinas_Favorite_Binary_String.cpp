//  E. Kachina's Favorite Binary String
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::string sl, sr;
    i32 l = 1, r = n, now = 0;
    std::cout << '?' << ' ' << l << ' ' << r << std::endl;
    std::cin >> now;
    if (now == 0) {
        std::cout << "! IMPOSSIBLE" << std::endl;
    } else {
        bool f = true;
        auto ql = [&]() {
            std::cout << '?' << ' ' << l + 1 << ' ' << r << std::endl;
            i32 tt;
            std::cin >> tt;
            if (tt == 0) {
                sl = sl + '0';
                f = false;
            } else if (tt < now) {
                sl = sl + '0';
                l++;
                now = tt;
            } else {
                sl = sl + '1';
                l++;
            }
        };
        auto qr = [&]() {
            std::cout << '?' << ' ' << l << ' ' << r - 1 << std::endl;
            i32 tt;
            std::cin >> tt;
            if (tt == 0) {
                sr = sl.back() + sr;
                r--;
            } else if (tt < now) {
                sr = '1' + sr;
                r--;
                now = tt;
            } else {
                sr = '0' + sr;
                r--;
            }
        };
        for (i32 i = 0; i + f < n - 1; i++) {
            if (f)ql();
            else qr();
        }
        if (f) {
            sl += "01";
        } else if (now == 0) {
            sl += sl.back();
        } else {
            sl += '1' - sl.back() + '0';
        }
        std::cout << "! " << sl << sr << std::endl;
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}