//  P14458 [ICPC 2025 Xi'an R]  Let's Make a Convex!
//  11:39
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};

void nhir() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector<int64> pre(n + 1);
    std::ranges::sort(v);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + v[i];
    }
    for (int i = 0; i < n; i++) {
        int64 p = 0;
        if ([&]() {
            for (int j = n - i - 1; ~j; j--) {
                if (v[j + i] < pre[j + i] - pre[j]) {
                    std::cout << pre[j + i + 1] - pre[j] << ' ';
                    return false;
                }
            }
            return true;
        }()) {
            std::cout << 0 << ' ';
        };
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