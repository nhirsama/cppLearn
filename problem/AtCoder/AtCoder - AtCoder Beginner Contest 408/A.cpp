//  Two Coins
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n, s;
    std::cin >> n >> s;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    std::ranges::sort(v);
    if (v[0] > s) {
        std::cout << "No\n";
        return;
    }
    for (i32 i = 0; i < n - 1; i++) {
        if (v[i + 1] - v[i] > s) {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}