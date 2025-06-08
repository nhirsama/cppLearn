//  E. Lost Soul
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> a(n + 4, -1), b(n + 4, -1);
    for (i32 i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (i32 i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    // for (auto &i: a) std::cin >> i;
    // for (auto &i: b) std::cin >> i;
    std::set<i32> aback1, aback2, aback3, bback1, bback2, bback3;
    for (i32 i = n - 1; ~i; i--) {
        if (a[i] == b[i]) {
            std::cout << i + 1 << endl;
            return;
        } else {
            aback1.insert(a[i + 1]);
            aback2.insert(a[i + 2]);
            bback1.insert(b[i + 1]);
            bback2.insert(b[i + 2]);
            // if (aback1.contains(b[i]) || bback1.contains(a[i])) {
            //     std::cout << i + 1 << endl;
            //     return;
            // }
            if (aback1.contains(a[i]) || bback1.contains(b[i])) {
                std::cout << i + 1 << endl;
                return;
            }
            // if (aback2.contains(a[i]) || bback2.contains(b[i])) {
            //     std::cout << i + 1 << endl;
            //     return;
            // }
            if (aback2.contains(b[i]) || bback2.contains(a[i])) {
                std::cout << i + 1 << endl;
                return;
            }
        }
    }
    std::cout << 0 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
