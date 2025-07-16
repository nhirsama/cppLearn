//  A. Deranged Deletions
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    int n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    for (i32 i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            std::cout << "YES\n" << 2 << endl << v[i] << ' ' << v[i + 1] << endl;
            return;
        }
    }
    std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}