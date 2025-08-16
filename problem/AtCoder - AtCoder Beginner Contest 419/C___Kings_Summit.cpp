//  C - King's Summit
//  下午8:29
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    int n;
    std::cin >> n;
    std::vector<std::array<int64, 2>> v(n);
    int64 a = 0, b = 0, c = 0x3f3f3f3f, d = 0x3f3f3f3f;
    for (auto &[x, y]: v) {
        int64 tx, ty;
        std::cin >> tx >> ty;
        x = tx + ty;
        y = tx - ty;
        a = std::max(a, tx);
        b = std::max(b, ty);
        c = std::min(c, tx);
        d = std::min(d, ty);
    }
    std::cout << (std::max(a - c, b - d) + 1) / 2 << endl;
//    std::ranges::sort(v, [](auto a, auto b) {
//        if (a[0] == b[0]) return a[1] < b[1];
//        return a[0] < b[0];
//    });
//    int64 ans = inf_i64;

//    std::ranges::sort(v, [](auto a, auto b) { return std::max(a[0], a[1]) < std::max(b[0], b[1]); });

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