//  Field of Fire
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, t;
    std::cin >> n >> t;
    std::string s;
    std::cin >> s;
    s += s;
    if (t >= n - 2) {
        std::cout << 0 << enld;
        return;
    }
    for (i32 i = t; i < n + t; i++) {

    }
//    for (i32 i = t; i < n + t; i++) {
//        if (s[i] == '1') {
//            s = s.substr(0, i - t) + std::string(2 * t - 1, '1') + s.substr(i + t);
//        }
//        i += t;
//    }
//    for (i32 i = 0; i < 2 * n - t; i++) {
//        if (s[i] == '1' && s[i + 1] == '0') {
//            for (i32 j = 0; j < t; j++) {
//                s[i + j + 1] = '1';
//            }
//            i += t;
//            continue;
//        }
//    }
//    for (i32 i = 2 * n - 1; i >= t; i--) {
//        if (s[i - 1] == '0' && s[i] == '1') {
//            for (i32 j = 0; j < t; j++) {
//                s[i - j - 1] = '1';
//            }
//            i -= t;
//            continue;
//        }
//    }
//    i32 ans = 0, cnt = 0;
//    for (i32 i = 0; i < n; i++) {
//        if (s[i] == '0') cnt++;
//    }
//    for (i32 i = n; i < 2 * n)
    std::cout << s << enld;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}