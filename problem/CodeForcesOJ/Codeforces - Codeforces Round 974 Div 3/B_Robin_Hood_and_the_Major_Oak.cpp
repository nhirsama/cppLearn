//  B. Robin Hood and the Major Oak
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::cout << (((n + 1) * n / 2 - (n - k) * (n - k + 1) / 2) % 2 ? "NO\n" : "YES\n");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
