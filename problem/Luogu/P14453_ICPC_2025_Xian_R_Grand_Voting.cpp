//  P14453 [ICPC 2025 Xi'an R] Grand Voting
//  11:31
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
    std::ranges::sort(v);
    int max = 0, min = 0;
    for (auto i: v) {
        if (max >= i) max++;
        else max--;
    }
    for (int i = n - 1; ~i; i--) {
        if (min < v[i]) min--;
        else min++;
    }
    std::cout << max << ' ' << min << enld;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        // std::cin >> T;
        while (T--) nhir();
    return 0;
}