//  D. Right Left Wrong
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    std::string s;
    std::cin >> s;
    std::vector<i32> pre(n + 1);
    for (i32 i = 0; i < n; i++) {
        pre[i + 1] += pre[i] + v[i];
    }
    i32 ans = 0;
    for (i32 l = 0, r = n - 1; l < r;) {
        while (l <= r && s[l] != 'L') l++;
        while (l <= r && s[r] != 'R') r--;
        if (l < r)ans += pre[r + 1] - pre[l];
        r--, l++;
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