//  D. 1D Eraser
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    i32 ans = 0;
    for (i32 i = 0; i < n; i++) {
        if (s[i] == 'B') {
            ans++;
            for (i32 j = 0; j < k && j + i < n; j++) {
                s[i + j] = 'W';
            }
            i += k - 1;
        }
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}