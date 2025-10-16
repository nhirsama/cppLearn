//  B. Pathless
//  下午2:15
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int n, x, sum = 0;
    std::cin >> n >> x;
    std::vector<int> v(n);
    for (auto &i: v) {
        std::cin >> i;
        sum += i;
    }
    if ((x - sum) <= 1 && x != sum) {
        std::ranges::sort(v, [](auto a, auto b) {
            if (a == 1) a += 2;
            if (b == 1) b += 2;
            return a < b;
        });
        for (auto i: v) std::cout << i << ' ';
        std::cout << endl;
        return;
    }
    std::cout << -1 << endl;
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