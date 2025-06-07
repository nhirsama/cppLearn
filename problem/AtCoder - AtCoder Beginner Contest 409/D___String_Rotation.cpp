//  D - String Rotation
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
    i32 i = 0;
    while (i + 1 < n && s[i] <= s[i + 1]) {
        i++;
    }
    if (i + 1 >= n) {
        std::cout << s << endl;
        return;
    }
    i32 r = i + 1;
    while (r + 1 < n && s[r + 1] <= s[i]) {
        r++;
    }
    std::cout << s.substr(0, i) << s.substr(i + 1, r - i) << s[i];
    if (r + 1 < n) std::cout << s.substr(r + 1);
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
