//  D. Gellyfish and Camellia Japonica
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, q;
    std::cin >> n >> q;
    std::vector<i32> c(n);
    for (auto &i: c) std::cin >> i;
    std::vector b(c);
    std::vector<std::array<i64, 3> > che(q);
    for (auto &[x,y,z]: che) {
        std::cin >> x >> y >> z;
        z--, y--, x--;
    }
    for (i32 i = q - 1; ~i; i--) {
        auto [x,y,z] = che[i];
        i32 t = c[z];
        c[z] = 0;
        c[y] = std::max(c[y], t);
        c[x] = std::max(c[x], t);
    }
    std::vector a(c);
    for (auto &[x,y,z]: che) {
        a[z] = std::min(a[x], a[y]);
    }
    for (i32 i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            std::cout << "-1\n";
            return;
        }
    }
    for (auto i: c) {
        std::cout << i << ' ';
    }
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
