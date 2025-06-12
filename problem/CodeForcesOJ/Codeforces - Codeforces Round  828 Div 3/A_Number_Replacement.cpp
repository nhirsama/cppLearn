//  A. Number Replacement
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    std::string s;
    std::cin >> s;
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < n; j++) {
            if (v[i] == v[j]) {
                if (s[i] != s[j]) {
                    std::cout << "NO\n";
                    return;
                }
            }
        }
    }
    std::cout << "YES\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}