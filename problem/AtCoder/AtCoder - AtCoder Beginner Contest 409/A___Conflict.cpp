//  A - Conflict
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    for (i32 i = 0; i < n; i++){
        if (a[i] == b[i] && a[i] == 'o') {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) nhir();
    return 0;
}
