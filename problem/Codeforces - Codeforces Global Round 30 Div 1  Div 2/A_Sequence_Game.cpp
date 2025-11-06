//  A. Sequence Game
//  22:40
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int n;
    std::cin >> n;
    int x;
    std::vector<int> v(n);
    for (auto &i: v) std::cin >> i;
    std::cin >> x;
    if (x <= *std::ranges::max_element(v) && x >= *std::ranges::min_element(v)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    };
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
