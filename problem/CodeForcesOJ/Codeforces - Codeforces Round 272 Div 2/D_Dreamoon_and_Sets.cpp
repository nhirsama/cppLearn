//  D. Dreamoon and Sets
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::cout << (6 * n - 1) * k << endl;
    for (i32 i = 0; i < n; i++) {
        std::cout << (6 * i + 1) * k << ' ' << (6 * i + 2) * k << ' ' << (6 * i + 3) * k << ' ' << (6 * i + 5) * k
                  << endl;
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}