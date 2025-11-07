//  C. Isamatdin and His Magic Wand!
//  15:10
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
    std::vector<int> v(n);
    int odd = 0, even = 0;
    for (auto &i: v) {
        std::cin >> i;
        if (i & 1) even++;
        else odd++;
    }
    if (even != 0 && odd != 0) {
        std::ranges::sort(v);
        for (auto &i: v) std::cout << i << ' ';
    } else {
        for (auto &i: v) std::cout << i << ' ';
    }
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
