//  B. Crafting
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> a(n), b(n);
    for (auto &i: a) std::cin >> i;
    for (auto &i: b) std::cin >> i;
    i32 del = 0;
    for (i32 i = 0; i < n; i++) {
        if (a[i] < b[i] && del == 0) del = b[i] - a[i];
        else if (a[i] < b[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    for (i32 i = 0; i < n; i++) {
        if (a[i] >= b[i] && a[i] - del < b[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}