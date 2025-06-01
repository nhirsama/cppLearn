//  G. Rock-Paper-Scissors
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    i32 ans = 0;
    for (i32 i = 0; i < n; i++) {
        for (i32 j = i; j < n; j++) {
            if (s[i] == 'e' && s[j] == 'f') ans += j - i;
        }
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}