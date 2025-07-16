//  A. Primary Task
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    std::string s;
    std::cin >> s;
    if (s.size() < 3) {
        std::cout << "NO\n";
        return;
    } else {
        if (s[0] == '1' && s[1] == '0') {
            if (s.size() == 3 && (s[2] == '0' || s[2] == '1')) {
                std::cout << "NO\n";
                return;
            } else if (s[2] == '0') {
                std::cout << "NO\n";
                return;
            } else {
                std::cout << "YES\n";
                return;
            }
        } else {
            std::cout << "NO\n";
            return;
        }
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