//  A. Team
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 n;
    std::cin >> n;
    i32 ans = 0;
    while (n--) {
        i32 a, b, c;
        std::cin >> a >> b >> c;
        ans += (a + b + c >= 2);
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}
