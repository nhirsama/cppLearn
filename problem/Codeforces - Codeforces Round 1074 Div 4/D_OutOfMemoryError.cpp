//  D. OutOfMemoryError
//  21:18
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    i32 n, m, h;
    std::cin >> n >> m >> h;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector<std::array<i32, 2> > op(m);
    for (auto &[x,y]: op) {
        std::cin >> x >> y;
    }
    auto v2 = v;
    std::vector<i32> use;
    for (auto [x,y]: op) {
        x--;
        use.push_back(x);
        v[x] += y;
        if (v[x] > h) {
            for (auto i: use) {
                v[i] = v2[i];
                use.clear();
            }
        }
    }
    for (auto i: v) std::cout << i << ' ';
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}
