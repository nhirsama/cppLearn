//  E. Sponsor of Your Problems
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    std::string a, b;
    std::cin >> a >> b;
    i32 ans = 0;
    i32 resa = 0, resb = 0;
    for (i32 i = 0; i < a.size(); i++) {
        if (a[i] == b[i] && resa == resb) ans += 2;
        else if (a[i] + 1 == b[i] && resa == resb) ans++;
        else if (a[i] == '9' && b[i] == '0' && resa == resb - 1) ans++;

        resa = resa * 10 + a[i] - '0';
        resb = resb * 10 + b[i] - '0';
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
