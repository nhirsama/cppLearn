//  Symmetry Intervals
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    while (q--) {
        std::string qs;
        std::cin >> qs;
        i32 a;
        std::cin >> a;
        i32 t = 0;
        i32 ans = 0;
        for (i32 i = 0; i < qs.size(); i++) {
            if (qs[i] == s[i + a - 1]) t++;
            else {
                if (t) ans += (t * (t - 1)) / 2 + t;
                t = 0;
            }
        }
        if (t) ans += (t * (t - 1)) / 2 + t;
        std::cout << ans << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}