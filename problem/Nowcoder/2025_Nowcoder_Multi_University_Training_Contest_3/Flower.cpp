//  Flower
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    int64 n, a, b;
    std::cin >> n >> a >> b;
    if (n <= a) {
        std::cout << "Sayonara\n";
    } else {
        int64 t = n % (a + b);
        if (t > a) {
            std::cout << 0 << enld;
        } else std::cout << t << endl;
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