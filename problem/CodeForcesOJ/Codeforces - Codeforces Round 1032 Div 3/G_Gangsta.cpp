//  G. Gangsta
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<i32> pre(n + 1);
    for (i32 i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] == '0' ? 1 : -1);
    }
    std::ranges::sort(pre);
    i32 ans = 0;
    for (i32 i = 0; i < n; i++) {
        ans += (i + 1) * (n - i);
    }
    for (i32 i = 1; i <= n; i++) {
        ans += (pre[i] - pre[i - 1]) * i * (n - i + 1);
    }
    std::cout << ans / 2 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}