//  P12834 [蓝桥杯 2025 国 B] 项链排列
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 a, b, c;
    std::cin >> a >> b >> c;
    std::string s;
    i32 ta = a, tb = b;
    if (a) {
        a--;
        s.push_back('L');
    } else if (b) {
        b--;
        s.push_back('Q');
    }
    for (i32 i = 0; i < c; i++) {
        if (s.back() == 'L') {
            s.push_back('Q');
            b--;
        } else if (s.back() == 'Q') {
            if (a == 0) {
                s = 'Q' + s;
                b--;
                continue;
            }
            s.push_back('L');
            a--;
        }
    }
    if (a > 0) {
        for (i32 i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                s = s.substr(0, i) + std::string(a, 'L') + s.substr(i);
                break;
            }
        }
    }
    if (b > 0) {
        for (i32 i = s.size() - 1; ~i; i--) {
            if (s[i] == 'Q') {
                s = s.substr(0, i) + std::string(b, 'Q') + s.substr(i);
                break;
            }
        }
    }
    if (ta + tb != s.size()) {
        std::cout << -1 << endl;
        return;
    }
    i32 cnt = 0;
    for (i32 i = 1; i < ta + tb; i++) {
        if (s[i] != s[i - 1]) cnt++;
    }
    if (cnt != c) {
        std::cout << -1 << endl;
        return;
    }
    std::cout << s << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) nhir();
    return 0;
}
