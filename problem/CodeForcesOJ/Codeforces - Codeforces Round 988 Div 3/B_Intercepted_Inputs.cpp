//  B. Intercepted Inputs
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 k;
    std::cin >> k;
    std::vector<i32> v(k);
    std::vector<bool> tot(k);
    for (i32 i = 0; i < k; i++)std::cin >> v[i], tot[v[i]] = true;
    for (i32 i = 1; i <= k - 2; i++) {
        if (((k - 2) % i == 0) && tot[(k - 2) / i] && tot[i]) {
            std::cout << i << ' ' << (k - 2) / i << endl;
            return;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
