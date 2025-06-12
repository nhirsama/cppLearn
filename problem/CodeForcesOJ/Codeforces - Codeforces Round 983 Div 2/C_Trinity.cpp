//  C. Trinity
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
    std::ranges::sort(v);
    i32 l = 0, r = n;
    auto check = [&](i32 mid) -> bool {
        for (i32 i = 0; i + mid <= n; i++) {
            if (v[i] + v[i + 1] > v[i + mid - 1]) return true;
        }
        return false;
    };
    while (l < r) {
        i32 mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    std::cout << n - l << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}