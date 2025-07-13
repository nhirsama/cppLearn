//  C. Password Cracking
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
//constexpr char endl = '\n';
//constexpr char enld = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::string s;
    auto qsuf = [&]() {
        std::cout << "? " << s + '0' << std::endl;
        i32 a;
        std::cin >> a;
        if (a) {
            s += '0';
            return 1;
        }
        std::cout << "? " << s + '1' << std::endl;
        std::cin >> a;
        if (a) {
            s += '1';
            return 1;
        }
        return 0;
    };

    auto qpre = [&]() {
        std::cout << "? " << '0' + s << std::endl;
        i32 a;
        std::cin >> a;
        if (a) {
            s = '0' + s;
            return 1;
        } else {
            s = '1' + s;
            return 1;
        }
        return 0;
    };

    for (i32 i = 0, f = 0; i < n; i++) {
        if (f == 0) {
            if (!qsuf()) {
                f = 1;
                qpre();
            }
        } else {
            qpre();
        }
    }
    std::cout << "! " << s << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}