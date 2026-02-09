//  P8622 [蓝桥杯 2014 国 B] 生物芯片
//  14:49
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};

void nhir() {
    i32 n, l, r;
    std::cin >> n >> l >> r;
    std::cout << (r - l + 1) - i32(sqrt(r) - sqrt(l - 1)) << endl;
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