//  A - Vacation Validation
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::string s;
    std::cin >> s;
//    int l, r;
//    std::cin >> l >> r;
    for (int i = l - 1; i < r; i++) {
        if (s[i] != 'o') {
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
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}