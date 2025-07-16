//  B. Above the Clouds
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::string s;
    std::cin >> n >> s;
    std::map<char, i32> m;
    for (auto i: s) m[i]++;
    if (s[0] == s.back()) m[s[0]]--;
    for (auto [x, y]: m) {
        if (y >= 2) {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
