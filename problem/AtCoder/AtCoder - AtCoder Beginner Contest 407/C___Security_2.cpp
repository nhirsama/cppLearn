//  C - Security 2
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    std::string s;
    std::cin >> s;
    i32 ans = 0, pi = 0;
    for (i32 i = s.size() - 1; ~i; i--) {
        if (i == s.size() - 1) {
            ans++;
            pi = s[i] - '0';
        } else {
            ans++;
            if (s[i] < s[i + 1]) {
                i32 t = pi % 10;
                if (t < s[i] - '0') pi += s[i] - '0' - t;
                else pi += 10 - t + s[i] - '0';
            } else pi += s[i] - s[i + 1];
        }
    }
    std::cout << ans + pi << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}