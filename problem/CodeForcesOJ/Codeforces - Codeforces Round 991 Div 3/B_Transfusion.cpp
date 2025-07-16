//  B. Transfusion
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
    i32 odd = 0, even = 0;
    for (i32 i = 0; i < n; i++) {
        if (i & 1) even += v[i];
        else odd += v[i];
    }
    std::swap(odd, even);
    if (odd % (n / 2) == 0 && even % ((n + 1) / 2) == 0 && (odd / (n / 2)) == (even / ((n + 1) / 2))) {
        std::cout << "YES\n";
        return;
    }
    std::cout << "NO\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
