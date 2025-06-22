//  A. Sakurako's Exam
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 a, b;
    std::cin >> a >> b;
    if (a == 0) {
        if (b % 2)
            std::cout << "NO" << endl;
        else
            std::cout << "YES" << endl;
    } else {
        if (a % 2)
            std::cout << "NO" << endl;
        else
            std::cout << "YES" << endl;
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
