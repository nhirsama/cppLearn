//  C. Equal Values
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
    for (auto &i: v)std::cin >> i;
    std::vector<i32> pre(n), suf(n);
    for (i32 i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) pre[i] = pre[i - 1];
        else pre[i] = i * v[i];
    }
    for (i32 i = n - 2; i >= 0; i--) {
        if (v[i] == v[i + 1]) suf[i] = suf[i + 1];
        else suf[i] = (n - i - 1) * v[i];
    }
    i32 ans = 0x3f3f3f3f3f3f3f3f;
    for (i32 i = 0; i < n; i++) {
        ans = std::min(ans, suf[i] + pre[i]);
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