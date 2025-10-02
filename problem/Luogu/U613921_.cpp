//  U613921 一道题教你学会猫娘语喵
//  11:36
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};

void nhir() {
    std::string s;
    std::cin >> s;
    for (auto i: s) {
        if (i == 'n') {
            std::cout << "nya";
        } else if (i == 'N') {
            std::cout << "NYA";
        } else {
            std::cout << i;
        }
    }
    std::cout << '\n';
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
